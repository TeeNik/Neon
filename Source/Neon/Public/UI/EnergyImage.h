// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "EnergyImage.generated.h"

enum class EnergyImageStatus
{
	Active, 
	Disable,
	Highlighted
};

UCLASS()
class NEON_API UEnergyImage : public UImage
{
	GENERATED_BODY()
	
public:

	FORCEINLINE void SetActive() { SetColorAndOpacity(ActiveColor); Status =  EnergyImageStatus::Active; }
	FORCEINLINE void SetDisable() {	SetColorAndOpacity(DisableColor); Status = EnergyImageStatus::Disable;	}
	FORCEINLINE void SetHighlighted() {	SetColorAndOpacity(HighlightedColor); Status = EnergyImageStatus::Highlighted; }
	FORCEINLINE EnergyImageStatus& GetStatus() { return Status; }

private:
	EnergyImageStatus Status;

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor ActiveColor;
	
	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor DisableColor;

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor HighlightedColor;
	
	
};
