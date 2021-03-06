// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnergyComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(OnStartTurnDelegate)
DECLARE_MULTICAST_DELEGATE(OnEndTurnDelegate)
DECLARE_MULTICAST_DELEGATE_TwoParams(OnSpendEnergyDelegate, int32, int32)


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEnergyComponent();

	FORCEINLINE int32& GetCurrentEnergy() { return CurrentEnergy; }
	FORCEINLINE int32& GetMaxEnergy() { return MaxEnergy; }
	void SpendEnergy(int32& value);

	void StartTurn();
	void EndTurn();

	OnStartTurnDelegate OnStartTurn;
	OnEndTurnDelegate OnEndTurn;
	OnSpendEnergyDelegate OnSpendEnergy;

	UPROPERTY(EditDefaultsOnly, Category = "Energy")
	int32 Initiative;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Energy")
	int32 MaxEnergy;

	int32 CurrentEnergy;
};
