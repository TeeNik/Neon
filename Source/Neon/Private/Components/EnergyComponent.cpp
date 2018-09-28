// Fill out your copyright notice in the Description page of Project Settings.

#include "EnergyComponent.h"
#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "System/TurnManager.h"



UEnergyComponent::UEnergyComponent()
{
}

void UEnergyComponent::BeginPlay()
{
	Super::BeginPlay();
	auto PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		CurrentEnergy = MaxEnergy;
		PC->ActionWidget->InitEnergy(CurrentEnergy);
	}
}

void UEnergyComponent::SpendEnergy(int32& value)
{
	CurrentEnergy -= value;
	if (CurrentEnergy == 0)
		SendEndTurn();
	else
		OnSpendEnergy.Broadcast();
}

void UEnergyComponent::StartTurn()
{
	OnStartTurn.Broadcast();
}

void UEnergyComponent::SendEndTurn()
{
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if(GM)
	{
		GM->GetTurnManager()->EndTurn();
	}
}



