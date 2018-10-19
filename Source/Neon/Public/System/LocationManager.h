// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WorldActors/GridBase.h"
#include "Components/WeaponComponent.h"
#include "LocationManager.generated.h"

DECLARE_MULTICAST_DELEGATE(OnSceneLoadedDelegate)

USTRUCT()
struct FGridBaseArray
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<AGridBase*> Array;
};

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API ULocationManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	ULocationManager();
	UPROPERTY()
	TArray<FGridBaseArray> GridArray;

	UPROPERTY(EditDefaultsOnly, Category = "LocationManager")
	TSubclassOf<AGridBase> GridBaseClass;

	Direction GetCoverInfo(const AGridBase* gridBase);
	OnSceneLoadedDelegate OnSceneLoaded;

	UFUNCTION()
	void SceneLoaded();

protected:
	virtual void BeginPlay() override;

private:
	bool IsTop(int i, int j);
};
