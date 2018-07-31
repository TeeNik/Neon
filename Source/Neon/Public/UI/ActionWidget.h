// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "ActionWidget.generated.h"

/**
 * 
 */
UCLASS()
class NEON_API UActionWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* RightButton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* UpperButton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* LeftButton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* LowerButton;
	
};
