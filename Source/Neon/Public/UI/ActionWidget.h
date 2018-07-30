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

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	UButton* Button;
	
};
