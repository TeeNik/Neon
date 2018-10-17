// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NeonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NeonPlayerController.h"
#include "System/UtilsLibrary.h"
#include "NeonGameMode.h"
#include "Materials/Material.h"
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
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
}

void ANeonCharacter::BeginPlay()
{
	Super::BeginPlay();
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->NeonCharacter = this;
	}
	PC->CreateFirstWidget();
	PC->ActionWidget->InitButtons(AbilityComp->Abilities);
	PC->ActionWidget->InitEnergy(EnergyComp->GetCurrentEnergy(), EnergyComp->OnSpendEnergy, EnergyComp->OnStartTurn, EnergyComp->OnEndTurn);
	EnergyComp->Initiative = 10;
}

void ANeonCharacter::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void ANeonCharacter::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void ANeonCharacter::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	GLog->Log("PlayerClick");
	if (ButtonPressed.GetFName() == "LeftMouseButton" &&isInRange)
	{
		ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if (EC) {
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Name;
			if (actionName.Equals(TEXT("DamageBust"))) {
				//WeaponComp->
			}
		}
	}
}

void ANeonCharacter::Deactivate_Implementation()
{

}

bool ANeonCharacter::Highlight_Implementation(FString& AbilityName)
{
	GetMesh()->SetRenderCustomDepth(true);
	isInRange = true;
	return true;
}
