// Fill out your copyright notice in the Description page of Project Settings.

#include "TurnManager.h"

UTurnManager::UTurnManager()
{
	
}

void UTurnManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentPlace = 0;
}

void UTurnManager::EndTurn()
{
	CurrentPlace++;
	if (CurrentPlace == Queue.Num()) CurrentPlace = 0;
	Queue[CurrentPlace]->StartTurn();
}

void UTurnManager::AddToQueue(UEnergyComponent* g)
{
	Queue.Add(g);
	Queue.Sort([](const UEnergyComponent& one, const UEnergyComponent& another) { return one.Initiative < another.Initiative; });
	for (UEnergyComponent* en : Queue)
	{
		GLog->Log(en->GetOwner()->GetName());
	}
}


