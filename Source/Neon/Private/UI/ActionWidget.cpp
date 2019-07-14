#include "ActionWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/Spacer.h"
#include "NeonGameMode.h"
#include "Components/HorizontalBoxSlot.h"
#include "UI/ActionButton.h"
#include "Ability/Ability.h"
#include "UI/EnergyImage.h"
#include "UI/ActionTooltip.h"
#include "UI/ActionButtonWidget.h"
#include "Action/ActionTableData.h"
#include "System/TurnManager.h"
#include "Components/HorizontalBox.h"
#include "Components/EnergyComponent.h"
#include "HealthInfoWidget.h"

void UActionWidget::ClearButtons()
{
	for (UActionButtonWidget* button : ButtonArray) {
		button->ActionButton->OnClicked.Clear();
	}
}

void UActionWidget::InitButtons(TArray<UAbility*> actionDatas)
{
	if(AbilityButton == NULL)
	{
		GLog->Log("Init Buttons Error!!! ActionButtonBP is null");
		return;
	}
	USpacer* spacer1 = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	USpacer* spacer2 = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	const FSlateChildSize size(ESlateSizeRule::Fill);
	const FMargin padding(0, 0, 15, 0);

	UHorizontalBoxSlot* child = ActionBox->AddChildToHorizontalBox(spacer1);
	child->SetSize(size);
	for(int i = 0; i < actionDatas.Num(); ++i)
	{
		UActionButtonWidget* button = WidgetTree->ConstructWidget<UActionButtonWidget>(AbilityButton);
		child = ActionBox->AddChildToHorizontalBox(button);
		child->SetPadding(padding);
		button->SetWidgetData(actionDatas[i]->Data);
		button->SetToolTip(ActionTooltip);
		ButtonArray.Add(button);
	}	
	child = ActionBox->AddChildToHorizontalBox(spacer2);
	child->SetSize(size);

	SkipButton->OnClicked.AddDynamic(this, &UActionWidget::SkipTurn);
}

void UActionWidget::InitEnergy(int32& num, OnSpendEnergyDelegate& onSpendEnergy, OnStartTurnDelegate& onStartTurn, OnEndTurnDelegate& onEndTurn)
{
	if(EnergyImageBP)
	{
		for (int i = 0; i < num; ++i)
		{
			UEnergyImage* image = WidgetTree->ConstructWidget<UEnergyImage>(EnergyImageBP);
			EnergyBox->AddChildToHorizontalBox(image);
			EnergyImages.Add(image);
		}
		onSpendEnergy.AddUFunction(this, FName("DisableEnergyImages"));
		onSpendEnergy.AddUFunction(this, FName("UpdateAbilityPanel"));
		onStartTurn.AddLambda([&]()
		{
			int maxEnergy = EnergyImages.Num();
			UpdateAbilityPanel(maxEnergy, maxEnergy);
			//SetVisibility(ESlateVisibility::Visible);;
			EnableEnergyImages(maxEnergy);
		});
		onEndTurn.AddLambda([&]()
		{
            GLog->Log("Widget End");
			//SetVisibility(ESlateVisibility::Hidden);
		});
	}
}

void UActionWidget::InitToolTip()
{
	if(ActionTooltipBP)
	{
		ActionTooltip = CreateWidget<UActionTooltip>(GetWorld()->GetFirstPlayerController(), ActionTooltipBP);
	}
}

void UActionWidget::ShowEnergyCost(const int32& current,const int32& cost)
{
	if (current < cost) return;
	int start = current - 1;
	for (int i = start; i > start - cost; --i) {
		EnergyImages[i]->SetHighlighted();
	}
}

void UActionWidget::HideEnergyCost(const int32& current)
{
	for (int i = 0; i < current; ++i) {
		EnergyImages[i]->SetActive();
	}
}

UHealthInfoWidget* UActionWidget::AddInfoWidget(uint32& id)
{
    const USpacer* spacer1 = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
    UHealthInfoWidget* widget = WidgetTree->ConstructWidget<UHealthInfoWidget>(InfoWidgetBP);
    InfoWidgetBox->AddChildToHorizontalBox(widget);
    InfoWidgets.Add(widget);
    widget->SetID(id);
    return widget;
}

void UActionWidget::DisableEnergyImages(int current, int value)
{
	int count = 0;
	for (int i = EnergyImages.Num()-1; i >= 0; --i)
	{
		if (EnergyImages[i]->GetStatus() == EnergyImageStatus::Active)
		{
			EnergyImages[i]->SetDisable();
			++count;
			if (count == value) return;
		}
	}
}

void UActionWidget::EnableEnergyImages(int value)
{
	int count = 0;
	for (int i = 0; i < EnergyImages.Num(); ++i)
	{
		if (EnergyImages[i]->GetStatus() == EnergyImageStatus::Disable)
		{
			EnergyImages[i]->SetActive();
			++count;
			if (count == value) return;
		}
	}
}

void UActionWidget::UpdateAbilityPanel(int current, int value)
{
	for (UActionButtonWidget* button : ButtonArray)
	{
		button->SetIsEnabled(current >= button->ActionButton->GetData()->Cost);
	}
}

void UActionWidget::SkipTurn()
{
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if (GM) {
		GM->GetTurnManager()->GetCurrentEC()->EndTurn();
	}
}

