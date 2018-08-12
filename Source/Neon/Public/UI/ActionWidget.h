// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "ActionWidget.generated.h"


enum ButtonDirection {
	Left,
	Upper,
	Right,
	Lower
};

UCLASS()
class NEON_API UActionWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UButton*> ButtonArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* RightButton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* UpperButton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* LeftButton;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* LowerButton;

	void ClearButtons();
	void ShowOnPosition(FVector2D& actorLocation);	
};
