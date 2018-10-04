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
	auto PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		CurrentEnergy = MaxEnergy;
		PC->ActionWidget->InitEnergy(CurrentEnergy, OnSpendEnergy);
	}

	auto GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if(GM)
	{
		GM->GetTurnManager()->AddToQueue(this);
	}

	//UUtilsLibrary::StaticTest("scrscrscr");
}

void UEnergyComponent::SpendEnergy(int32& value)
{
	CurrentEnergy -= value;
	if (CurrentEnergy == 0)
		SendEndTurn();
	else
		OnSpendEnergy.Broadcast(value);
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



//4261012587614729
//1650