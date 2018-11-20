// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ActionButton.generated.h"

struct FActionTableData;

UCLASS()
class NEON_API UActionButton : public UButton
{
	GENERATED_BODY()

private:
	
	FActionTableData* Data;
	
public:

	FActionTableData* GetData() { return Data; }

	void SetButtonData(FActionTableData* data);

	UFUNCTION()
	void ExecuteAbility();
	
	void DisableAbility();

	UFUNCTION()
	void OnButtonHoverBegin();
	UFUNCTION()
	void OnButtonHoverEnd();
};
