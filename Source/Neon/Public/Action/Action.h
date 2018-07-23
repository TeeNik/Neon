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
	int SomeInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionData")
	FString Description;

	FActionData() {
		SomeInt = 3315;
		Description = TEXT("None");
	}

	void SetSomeInt(const int value) {
		SomeInt = value;
	}

	int GetSomeInt() {
		return SomeInt;
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


