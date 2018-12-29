// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionButtonWidget.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class NEON_API UActionButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* MyButton;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MyText;
};
