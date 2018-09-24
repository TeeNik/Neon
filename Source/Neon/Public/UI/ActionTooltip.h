// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "ActionTooltip.generated.h"

UCLASS()
class NEON_API UActionTooltip : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetData(FText title, FText desc, FText cooldown, int32 energy);

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
