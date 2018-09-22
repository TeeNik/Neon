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

	FORCEINLINE void SetActive() { ColorAndOpacity = ActiveColor; }
	FORCEINLINE void SetDisable() { ColorAndOpacity = DisableColor;	}
	FORCEINLINE void SetHighlighted() { ColorAndOpacity = HighlightedColor; }

private:

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor ActiveColor;
	
	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor DisableColor;

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	FLinearColor HighlightedColor;
	
	
};
