// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionButton.h"
#include "NeonPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "NeonCharacter.h"
//include "Components/AbilityComponent.h"

void UActionButton::SetButtonData(FActionTableData* data)
{
	Data = *data;
	WidgetStyle.Normal.SetResourceObject(data->Icon);
	WidgetStyle.Hovered.SetResourceObject(data->Icon);
	WidgetStyle.Pressed.SetResourceObject(data->Icon);
	OnClicked.AddDynamic(this, &UActionButton::ExecuteAbility);
	OnHovered.AddDynamic(this, &UActionButton::OnButtonHover);
}

void UActionButton::ExecuteAbility()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->NeonCharacter->GetAbilityConponent()->ShowAbilityRange(Data.Name);
	}
}


void UActionButton::DisableAbility()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->ActiveAction = nullptr;
		PC->NeonCharacter->GetAbilityConponent()->ShowAbilityRange(Data.Name);
	}
}

void UActionButton::OnButtonHover()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->ActionWidget->GetActionTooltip()->SetData(Data);
	}
}
