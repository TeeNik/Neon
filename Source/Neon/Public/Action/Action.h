// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include "Action.generated.h"


USTRUCT(BlueprintType)
struct FActionData
{
	GENERATED_BODY()

	//void(*ActionFunc)(void);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionData")
	int Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionData")
	FString Description;

	typedef void (FActionData::*FunctionPtrType)(void);
	FunctionPtrType ActionFunction;

	FActionData() {
		Cost = 0;
		Description = TEXT("None");
		ActionFunction = NULL;
	}

	void SetCost(const int value) {
		Cost = value;
	}

	int GetCost() {
		return Cost;
	}

	void SetDescription(const FString& str) {
		Description = str;
	}

	FString GetDescription() {
		return Description;
	}
};

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
		FActionData GetActionList();
};


