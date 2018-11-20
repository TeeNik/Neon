// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TurnManager.generated.h"

class UEnergyComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UTurnManager : public USceneComponent
{
	GENERATED_BODY()


public:	
	UTurnManager();

	void AddToQueue(UEnergyComponent* g);
	FORCEINLINE void RemoveFromQueue(UEnergyComponent* g) { Queue.Remove(g); }
	FORCEINLINE UEnergyComponent* GetCurrentEC() { return Queue[CurrentPlace]; }

	void EndTurn();

protected:
	virtual void BeginPlay() override;
	
private:
	TArray<UEnergyComponent*> Queue;
	int CurrentPlace;
};
