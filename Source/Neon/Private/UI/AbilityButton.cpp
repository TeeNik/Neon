// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionButton.h"
#include "ResourceManagerLibrary.h"
#include "NeonPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AbilityComponent.h"
#include "NeonCharacter.h"
#include "Action/ActionTableData.h"

void UActionButton::SetButtonData(FName abilityName)
{
	UDataTable* actionTable = UResourceManagerLibrary::GetData()->ActionDataTable;
	FActionTableData* actionData = actionTable->FindRow<FActionTableData>(abilityName, TEXT(""));
	WidgetStyle.Normal.SetResourceObject(actionData->Icon);
	
}

void UActionButton::ExecuteAbility()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->ActiveAction = AbilityName;
		ANeonCharacter* character = Cast<ANeonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if (character)
		{
			character->GetAbilityConponent()->ShowAbilityRange(AbilityName);
		}

	}
}
