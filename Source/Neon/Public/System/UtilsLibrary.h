// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "UtilsLibrary.generated.h"

UCLASS()
class NEON_API UUtilsLibrary : public UObject
{
	GENERATED_BODY()

public:


	template<class T>
	FORCEINLINE static T* GetRelativeComponent(UActorComponent* comp)
	{
		return Cast<T>(comp->GetOwner()->GetComponentByClass(T::StaticClass()));
	}	

	template<class T>
	FORCEINLINE static T* GetComponentByClass(AActor* actor)
	{
		return Cast<T>(actor->GetComponentByClass(T::StaticClass()));
	}
};