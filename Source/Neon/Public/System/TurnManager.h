// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TurnManager.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(OnNextTurnDelegate, int32)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UTurnManager : public USceneComponent
{
	GENERATED_BODY()


public:	
	UTurnManager();

	OnNextTurnDelegate OnNextTurn;

	FORCEINLINE void AddToQueue(int32 g) { Queue.Add(g); }
	FORCEINLINE void RemoveFromQueue(int32 g) { Queue.Remove(g); }

protected:
	virtual void BeginPlay() override;
	
private:
	TArray<int32> Queue;
};
