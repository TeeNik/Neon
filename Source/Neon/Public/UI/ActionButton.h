// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/AbilityComponent.h"
#include "Action/ActionTableData.h"
#include "ActionButton.generated.h"


UCLASS()
class NEON_API UActionButton : public UButton
{
	GENERATED_BODY()
	
	
public:

	FName AbilityName;

	void SetButtonData(FName abilityName);

	UFUNCTION()
	void ExecuteAbility();
	
};
