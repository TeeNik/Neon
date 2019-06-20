#include "MotionComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NeonGameMode.h"
#include "NeonCharacter.h"
#include "WorldActors/GridBase.h"
#include "GridLocationComponent.h"
#include "Engine/World.h"

UMotionComponent::UMotionComponent()
{

}

void UMotionComponent::BeginPlay()
{
	Super::BeginPlay();

	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* LocationManager = GM->GetLocationManager();
}

void UMotionComponent::SetupInitialPosition(AGridBase* gridBase)
{
	FVector gridLocation = gridBase->GetActorLocation();
	gridLocation.Z += 70;
	GetOwner()->SetActorLocation(gridLocation);
	Position = gridBase;
}

void UMotionComponent::MoveToGrid(AActor* gridBase)
{
	ACharacter* character = Cast<ACharacter>(GetOwner());
	if (character->bIsCrouched) {
		character->UnCrouch();
	}

	AGridBase* grid = Cast<AGridBase>(gridBase);
	AAIController* aiController = Cast<AAIController>(character->GetController());
	aiController->MoveToLocation(gridBase->GetActorLocation(), -1, false);
    Position->GetLocationComponent()->SetStatus(GridLocationStatus::Empty);
	Position = grid;

    bool isPlayer = character->IsA(ANeonCharacter::StaticClass());
    GridLocationStatus newStatus = isPlayer ? GridLocationStatus::Player : GridLocationStatus::Enemy;
    Position->GetLocationComponent()->SetStatus(newStatus);
}

