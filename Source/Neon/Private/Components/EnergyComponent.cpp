// Fill out your copyright notice in the Description page of Project Settings.

#include "EnergyComponent.h"
#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "System/UtilsLibrary.h"
#include "System/TurnManager.h"

UEnergyComponent::UEnergyComponent()
{
}

void UEnergyComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentEnergy = MaxEnergy;
	auto GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if(GM)
	{
		GM->GetTurnManager()->AddToQueue(this);
	}
}

void UEnergyComponent::SpendEnergy(int32& value)
{
	CurrentEnergy -= value;
	OnSpendEnergy.Broadcast(CurrentEnergy, value);

	if (CurrentEnergy == 0)
		EndTurn();
}

void UEnergyComponent::StartTurn()
{
	GLog->Log("start turn");
	CurrentEnergy = MaxEnergy;
	OnStartTurn.Broadcast();
}

void UEnergyComponent::EndTurn()
{
	OnEndTurn.Broadcast();
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if(GM)
	{
		GM->GetTurnManager()->EndTurn();
	}
}