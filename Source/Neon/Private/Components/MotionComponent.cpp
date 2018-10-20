// Fill out your copyright notice in the Description page of Project Settings.

#include "MotionComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "NeonGameMode.h"

UMotionComponent::UMotionComponent()
{

}


void UMotionComponent::BeginPlay()
{
	Super::BeginPlay();

	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* LocationManager = GM->GetLocationManager();
	LocationManager->OnSceneLoaded.AddUFunction(this, "SetupInitialPosition");
}

void UMotionComponent::SetupInitialPosition()
{
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* LocationManager = GM->GetLocationManager();
	AGridBase* gridBase = LocationManager->GridArray[Row].Array[Column];
	FVector gridLocation = gridBase->GetActorLocation();
	gridLocation.Z += 70;
	GetOwner()->SetActorLocation(gridLocation);
	Position = gridBase;
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

