// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "UI/ActionButton.h"
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
	
private:
	void SetButtonImage(ButtonDirection direction, UTexture2D* texture);
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UActionButton*> ButtonArray;

	void ClearButtons();
	void InitButtons(FActionTableData* actionDatas);
};
