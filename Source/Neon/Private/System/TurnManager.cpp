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
	//GLog->Log("EndTurn");
	CurrentPlace++;
	if (CurrentPlace == Queue.Num()) CurrentPlace = 0;
	Queue[CurrentPlace]->StartTurn();
}



