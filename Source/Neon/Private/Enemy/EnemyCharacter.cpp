// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "LocationManager.h"
#include "NeonGameMode.h"
#include "System/UtilsLibrary.h"
#include "NeonPlayerController.h"
#include "Commands/ShootCommand.h"

AEnemyCharacter::AEnemyCharacter()
{
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
	EnergyComp->Initiative = 3;
	SelectionCircle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionCircle"));
	SelectionCircle->SetupAttachment(RootComponent);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UCapsuleComponent* capsule = GetCapsuleComponent();
	capsule->OnBeginCursorOver.AddDynamic(this, &AEnemyCharacter::OnBeginCursorOver);
	capsule->OnEndCursorOver.AddDynamic(this, &AEnemyCharacter::OnEndCursorOver);
	capsule->OnClicked.AddDynamic(this, &AEnemyCharacter::OnClicked);

	EnergyComp->OnStartTurn.AddLambda([&]()
	{
		EnergyComp->EndTurn();
	});
}

void AEnemyCharacter::InitialMovement()
{
	SetActorLocation(FVector());
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* locationMan = GM->GetLocationManager();
}

void AEnemyCharacter::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, HighlightMaterial);
	}
}

void AEnemyCharacter::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, DefaultMaterial);
	}
}

void AEnemyCharacter::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{

	if(isInRange)
	{
		Command* command = NULL;
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if(EC)
		{
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Name;
			if (actionName == TEXT("Shoot"))
			{
				UWeaponComponent* weaponComp = UUtilsLibrary::GetRelativeComponent<UWeaponComponent>(EC);
				command = new ShootCommand(weaponComp, MotionComp);
			}
			command->Execute();
			EC->SpendEnergy(actionComp->ActiveAction->Cost);
		}
	}
}

void AEnemyCharacter::Deactivate_Implementation()
{
	isInRange = false;
	SelectionCircle->SetMaterial(0, DefaultMaterial);
}

bool AEnemyCharacter::Highlight_Implementation(FString& AbilityName)
{
	isInRange = true;
	return true;
}

void AEnemyCharacter::HideCircle()
{
	SelectionCircle->SetVisibility(false);
}