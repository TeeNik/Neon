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
		int energy = 10;
		PC->ActionWidget->InitEnergy(energy);
	}
}

void UEnergyComponent::SpendEnergy(int32& value)
{
	CurrentEnergy -= value;
}

void UEnergyComponent::SendEndTurn()
{
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if(GM)
	{
		GM->GetTurnManager()->EndTurn();
	}
}



