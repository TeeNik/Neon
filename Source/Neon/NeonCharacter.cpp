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
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	AbilityComp = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbilityComponent"));
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
}

void ANeonCharacter::BeginPlay()
{
	Super::BeginPlay();
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->NeonCharacter = this;
	}
}
