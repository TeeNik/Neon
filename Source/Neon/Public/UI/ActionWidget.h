// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/ActionButton.h"
#include "UI/EnergyImage.h"
#include "Components/HorizontalBox.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UEnergyImage*> EnergyImages;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UHorizontalBox* EnergyBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	UHorizontalBox* ActionBox;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEnergyImage> EnergyImageBP;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UActionButton> ActionButtonBP;

	void ClearButtons();
	void InitButtons(TArray<FActionTableData*> actionDatas);
	void InitEnergy(int32& num);
};
