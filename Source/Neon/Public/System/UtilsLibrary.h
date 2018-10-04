// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "UtilsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NEON_API UUtilsLibrary : public UObject
{
	GENERATED_BODY()

private:

	ANeonPlayerController * NeonPC;
	ANeonGameMode* NeonGM;

public:
	template<class T>
	FORCEINLINE static T* GetRelativeComponent(UActorComponent* comp)
	{
		return Cast<T>(comp->GetOwner()->GetComponentByClass(T::StaticClass()));
	}	

	/*FORCEINLINE static ANeonGameMode* GetNeonGM()
	{
		return Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	}

	FORCEINLINE static ANeonPlayerController* GetNeonPC()
	{
		return Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	}*/
};