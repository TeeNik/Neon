// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.generated.h"


USTRUCT(BlueprintType)
struct FActionData
{
	GENERATED_BODY()

	//void(*ActionFunc)(void);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionData")
	int SomeInt;

	FActionData() {
		SomeInt = 3315;
	}

	void SetSomeInt(const int value) {
		SomeInt = value;
	}

	int GetSomeInt() {
		return SomeInt;
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
