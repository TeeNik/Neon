// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameStrings.generated.h"

UCLASS()
class NEON_API UGameStrings : public UObject
{
	GENERATED_BODY()

	static const FString DamageBustAction;
	static const FString AccuranceBustAction;
	static const FString ShootAction;
	static const FString OverloadAction;
	static const FString ActivateAction;

};
