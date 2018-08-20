// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NeonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NeonPlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "WorldActors/GridBase.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

ANeonCharacter::ANeonCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	AbilityComp = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbilityComponent"));
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
}

void ANeonCharacter::BeginPlay()
{
	Super::BeginPlay();
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->NeonCharacter = this;
	}
}

void ANeonCharacter::GetMovementArea()
{
	TArray<FHitResult> HitResults;
	FVector StartLocation = GetActorLocation();
	FVector EndLocation = GetActorLocation();
	EndLocation.Z += 0;

	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(350);
	bool bHitSomething = GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);
	if (bHitSomething)
	{
		for (auto It = HitResults.CreateIterator(); It; It++)
		{
			GLog->Log((*It).Actor->GetName());
			AGridBase* grid = Cast<AGridBase>(It->GetActor());
			if (grid) {
				grid->Highlight();
			}
		}
	}
	FVector CenterOfSphere = ((EndLocation - StartLocation) / 2) + StartLocation;
}
