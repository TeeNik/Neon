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
	if (CurrentEnergy == 0)
		EndTurn();
	else
		OnSpendEnergy.Broadcast(value);
}

void UEnergyComponent::StartTurn()
{
	//OnEndTurn.Broadcast();
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