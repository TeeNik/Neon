// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/Spacer.h"
#include "Components/HorizontalBoxSlot.h"

void UActionWidget::ClearButtons()
{
	for (UButton* button : ButtonArray) {
		button->OnClicked.Clear();
	}
}

void UActionWidget::InitButtons(TArray<FActionTableData*> actionDatas)
{
	if(ActionButtonBP == NULL)
	{
		GLog->Log(("Init Buttons Error!!! ActionButtonBP is null"));
		return;
	}
	const auto spacer1 = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	const auto spacer2 = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	const FSlateChildSize size(ESlateSizeRule::Fill);
	const FMargin padding(0, 0, 15, 0);

	auto child = ActionBox->AddChildToHorizontalBox(spacer1);
	child->SetSize(size);
	for(int i = 0; i < actionDatas.Num(); ++i)
	{
		UActionButton* button = WidgetTree->ConstructWidget<UActionButton>(ActionButtonBP);
		child = ActionBox->AddChildToHorizontalBox(button);
		child->SetPadding(padding);
		button->SetButtonData(actionDatas[i]);
		button->SetToolTip(ActionTooltip);
		ButtonArray.Add(button);
	}	
	child = ActionBox->AddChildToHorizontalBox(spacer2);
	child->SetSize(size);
}

void UActionWidget::InitEnergy(int32& num)
{
	if(EnergyImageBP)
	{
		for (int i = 0; i < num; ++i)
		{
			UEnergyImage* image = WidgetTree->ConstructWidget<UEnergyImage>(EnergyImageBP);
			EnergyBox->AddChildToHorizontalBox(image);
		}
	}
}

void UActionWidget::InitToolTip()
{
	if(ActionTooltipBP)
	{
		ActionTooltip = CreateWidget<UActionTooltip>(GetWorld()->GetFirstPlayerController(), ActionTooltipBP);
	}
}

