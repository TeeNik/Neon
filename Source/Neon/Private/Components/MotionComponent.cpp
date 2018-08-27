// Fill out your copyright notice in the Description page of Project Settings.

#include "MotionComponent.h"
#include "GameFramework/Character.h"
#include "AI/Navigation/NavigationSystem.h"

UMotionComponent::UMotionComponent()
{

}


void UMotionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMotionComponent::MoveToGrid(AGridBase* gridBase)
{
	ACharacter* character = Cast<ACharacter>(GetOwner());
	UNavigationSystem::SimpleMoveToActor(character->GetController(), gridBase);
}

