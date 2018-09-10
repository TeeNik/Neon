// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WorldActors/GridBase.h"
#include "LocationManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API ULocationManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	ULocationManager();
	TArray<TArray<AGridBase*>> GridArray;

	UPROPERTY(EditDefaultsOnly, Category = "LocationManager")
	TSubclassOf<AGridBase> GridBaseClass;

protected:
	virtual void BeginPlay() override;
};
