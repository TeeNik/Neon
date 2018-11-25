#include "ActionButton.h"
#include "NeonPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/EnergyComponent.h"
#include "Action/ActionTableData.h"
#include "Engine/Texture2D.h"
#include "NeonCharacter.h"
#include "UI/ActionWidget.h"
#include "UI/ActionTooltip.h"
#include "Components/AbilityComponent.h"

void UActionButton::SetButtonData(FActionTableData* data)
{
	Data = data;
	WidgetStyle.Normal.SetResourceObject(data->Icon);
	WidgetStyle.Hovered.SetResourceObject(data->Icon);
	WidgetStyle.Pressed.SetResourceObject(data->Icon);
	WidgetStyle.Disabled.SetResourceObject(data->Icon);
	OnClicked.AddDynamic(this, &UActionButton::ExecuteAbility);
	OnHovered.AddDynamic(this, &UActionButton::OnButtonHoverBegin);
	OnUnhovered.AddDynamic(this, &UActionButton::OnButtonHoverEnd);
}

void UActionButton::ExecuteAbility()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->NeonCharacter->GetAbilityConponent()->ShowAbilityRange(Data->Name);
	}
}


void UActionButton::DisableAbility()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->ActiveAction = nullptr;
		PC->NeonCharacter->GetAbilityConponent()->ShowAbilityRange(Data->Name);
	}
}

void UActionButton::OnButtonHoverBegin()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		int32 current = PC->NeonCharacter->GetEnergyComponent()->GetCurrentEnergy();
		PC->ActionWidget->GetActionTooltip()->SetData(Data);
		PC->ActionWidget->ShowEnergyCost(current, Data->Cost);
	}
}

void UActionButton::OnButtonHoverEnd()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		int32 current = PC->NeonCharacter->GetEnergyComponent()->GetCurrentEnergy();
		PC->ActionWidget->HideEnergyCost(current);
		PC->ActionWidget->GetActionTooltip()->SetData(Data);
	}
}
