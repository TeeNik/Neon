// Fill out your copyright notice in the Description page of Project Settings.

#include "MotionComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"
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
	//UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
	AAIController* aiController = Cast<AAIController>(character->GetController());
	aiController->MoveToLocation(gridBase->GetActorLocation(), -1, false);
	Position = gridBase;
	//NavSys->SimpleMoveToLocation(character->GetController(), gridBase->GetActorLocation());
}

