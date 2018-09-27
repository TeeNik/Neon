// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "EnergyImage.generated.h"

/**
 * 
 */
UCLASS()
class NEON_API UEnergyImage : public UImage
{
	GENERATED_BODY()
	
public:

	FORCEINLINE void SetActive() { SetColorAndOpacity(ActiveColor); }
	FORCEINLINE void SetDisable() { SetColorAndOpacity(DisableColor);	}
	FORCEINLINE void SetHighlighted() { SetColorAndOpacity(HighlightedColor); }

private:

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor ActiveColor;
	
	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor DisableColor;

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor HighlightedColor;
	
	
};
