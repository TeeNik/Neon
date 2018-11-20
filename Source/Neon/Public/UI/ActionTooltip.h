// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionTooltip.generated.h"

class UImage;
class UTextBlock;
class UUserWidget;
struct FActionTableData;

UCLASS()
class NEON_API UActionTooltip : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//UFUNCTION(BlueprintCallable)
	void SetData(FActionTableData* data);

protected:
	UPROPERTY(BlueprintReadWrite, Category="UI")
	UTextBlock* Title;
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UTextBlock* Description;
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UTextBlock* Cooldown;
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UImage* Energy;
	
};
