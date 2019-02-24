#include "MotionComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NeonGameMode.h"
#include "WorldActors/GridBase.h"
#include "System/LocationManager.h"
#include "Engine/World.h"

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

void UMotionComponent::MoveToGrid(AActor* gridBase)
{
	ACharacter* character = Cast<ACharacter>(GetOwner());
	AGridBase* grid = Cast<AGridBase>(gridBase);
	//UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
	AAIController* aiController = Cast<AAIController>(character->GetController());
	aiController->MoveToLocation(gridBase->GetActorLocation(), -1, false);
	Position = grid;
	//UAIBlueprintHelperLibrary::SimpleMoveToLocation(aiController, gridBase->GetActorLocation());
}

