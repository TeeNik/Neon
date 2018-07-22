// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.generated.h"


UINTERFACE(BlueprintType)
class NEON_API UAction : public UInterface
{
	GENERATED_BODY()
};

class NEON_API IAction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	bool GetActionList();

};
