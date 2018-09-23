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
	void SetData(FText title, FText desc, FText cost, int32 energy);

private:
	UPROPERTY(VisibleAnywhere, Category="UI")
	UTextBlock* Title;
	UPROPERTY(VisibleAnywhere, Category = "UI")
	UTextBlock* Description;
	UPROPERTY(VisibleAnywhere, Category = "UI")
	UTextBlock* Cost;
	UPROPERTY(VisibleAnywhere, Category = "UI")
	UImage* Energy;
	
};
