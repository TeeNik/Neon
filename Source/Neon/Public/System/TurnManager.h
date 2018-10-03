// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/EnergyComponent.h"
#include "TurnManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UTurnManager : public USceneComponent
{
	GENERATED_BODY()


public:	
	UTurnManager();

	
	//OnNextTurnDelegate OnNextTurn;

	FORCEINLINE void AddToQueue(UEnergyComponent* g) { Queue.Add(g); }
	FORCEINLINE void RemoveFromQueue(UEnergyComponent* g) { Queue.Remove(g); }
	FORCEINLINE UEnergyComponent* GetCurrentEC() { return Queue[CurrentPlace]; }


	void EndTurn();

protected:
	virtual void BeginPlay() override;
	
private:
	TArray<UEnergyComponent*> Queue;
	int CurrentPlace;
};
