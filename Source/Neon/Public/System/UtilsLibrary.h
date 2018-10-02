// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "UtilsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NEON_API UUtilsLibrary : public UObject
{
	GENERATED_BODY()

public:
	template<class T>
	FORCEINLINE T* GetRelativeComponent(TSubclassOf<UActorComponent> comp, UClass* cls)
	{
		return Cast<cls>(comp->GetOwner()->GetComponentByClass(cls));
	}
	


	
};