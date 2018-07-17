// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NeonPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "NeonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANeonPlayerController::ANeonPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bEnableMouseOverEvents = true;
}

void ANeonPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ANeonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ANeonPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ANeonPlayerController::OnSetDestinationReleased);
}

void ANeonPlayerController::OnSetDestinationPressed()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANeonCharacter::StaticClass(), FoundActors);
	FHitResult Hit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
	FVector MoveLocation;
	if (ANeonCharacter* MyPawn = Cast<ANeonCharacter>(FoundActors[0]))
	{
		if (MyPawn->GetCursorToWorld())
		{
			GLog->Log("1");
			UNavigationSystem::SimpleMoveToActor(MyPawn->GetController(), Hit.GetActor());
		}
	}
}

void ANeonPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	//bMoveToMouseCursor = false;
}
