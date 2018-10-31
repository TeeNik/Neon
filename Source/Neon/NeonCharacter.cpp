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

	SelectionCircle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionCircle"));
	SelectionCircle->SetupAttachment(RootComponent);
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
	EnergyComp->OnSpendEnergy.AddUFunction(this, "OnSpendEnergy");
	WeaponComp->Init(EnergyComp->OnEndTurn);
	UCapsuleComponent* capsule = GetCapsuleComponent();
	capsule->OnBeginCursorOver.AddDynamic(this, &ANeonCharacter::OnBeginCursorOver);
	capsule->OnEndCursorOver.AddDynamic(this, &ANeonCharacter::OnEndCursorOver);
	capsule->OnClicked.AddDynamic(this, &ANeonCharacter::OnClicked);
}

void ANeonCharacter::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, HighlightMaterial);
	}
}

void ANeonCharacter::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, DefaultMaterial);
	}
}

void ANeonCharacter::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" &&isInRange)
	{
		FString name = AbilityComp->ActiveAction->Name;
		if (name == DamageBustAction) {
			WeaponComp->BustDamage(1.5f);
		}
		else if (name == AccuranceBustAction) {
			WeaponComp->BustAccuracy(20);
		}
		EnergyComp->SpendEnergy(AbilityComp->ActiveAction->Cost);
	}
}

void ANeonCharacter::Deactivate_Implementation()
{

}

bool ANeonCharacter::Highlight_Implementation(FString& AbilityName)
{
	isInRange = true;
	return true;
}

void ANeonCharacter::OnSpendEnergy(int current, int value)
{
	AbilityComp->HideAbilityRange();
}
