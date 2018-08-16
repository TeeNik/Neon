// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionButton.h"
#include "NeonPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "NeonCharacter.h"
//include "Components/AbilityComponent.h"

void UActionButton::SetButtonData(FActionTableData* data)
{
	Data = data;
	WidgetStyle.Normal.SetResourceObject(data->Icon);
	WidgetStyle.Hovered.SetResourceObject(data->Icon);
	WidgetStyle.Pressed.SetResourceObject(data->Icon);
}

void UActionButton::ExecuteAbility()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->ActiveAction = Data->Name;
		ANeonCharacter* character = Cast<ANeonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (character)
		{
			character->GetAbilityConponent()->ShowAbilityRange(Data->Name);
		}

	}
}