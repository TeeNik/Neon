// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Action/ActionTableData.h"
#include "ActionButton.generated.h"

UCLASS()
class NEON_API UActionButton : public UButton
{
	GENERATED_BODY()

private:
	
	FActionTableData* Data;
	
public:
	void SetButtonData(FActionTableData* data);

	UFUNCTION()
	void ExecuteAbility();
	
};
