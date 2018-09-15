// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "WorldActors/GridBase.h"
#include "LocationManager.generated.h"


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

	bool IsUnderCover(AGridBase* gridBase);

protected:
	virtual void BeginPlay() override;

private:
	bool IsTop(int i, int j);
};
