// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Action/Action.h"
#include "ActionTableData.generated.h"

UENUM(BlueprintType)
enum ActionName {
	BlockUp,
	BlockDown,
	Shoot,
};

USTRUCT(BlueprintType)
struct NEON_API FActionTableData : public FTableRowBase
{
	GENERATED_BODY()

public:
	
	FActionTableData() {
		Cost = 2;
		Description = TEXT("None");
	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	ActionName actionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	int32 Cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	float  Range;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	TSubclassOf<class UAction>  MyClassType;
};
