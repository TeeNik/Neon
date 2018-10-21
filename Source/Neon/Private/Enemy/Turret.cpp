// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Components/AbilityComponent.h"
#include "System/UtilsLibrary.h"


ATurret::ATurret()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//RootComponent = MeshComp;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));

	Status = TurretStatus::DisableTurret;
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATurret::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void ATurret::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void ATurret::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" && isInRange)
	{
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if (EC) {
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Name;
			if (actionName == ActivateAbility)
			{

			}
		}
	}
}

void ATurret::Deactivate_Implementation()
{
	MeshComp->SetRenderCustomDepth(false);
	isInRange = false;
}

bool ATurret::Highlight_Implementation(FString& AbilityName)
{
	if (AbilityName == ActivateAbility && Status != TurretStatus::DisableTurret)
		return false;
	GLog->Log("Test");

	MeshComp->SetRenderCustomDepth(true);
	isInRange = true;
	return true;
}

void ATurret::ActivateByPlayer()
{
	MeshComp->SetMaterial(1, PlayerMaterial);
	MeshComp->SetMaterial(4, PlayerMaterial);
}

void ATurret::ActivateByEnemy()
{
	MeshComp->SetMaterial(1, EnemyMaterial);
	MeshComp->SetMaterial(4, EnemyMaterial);
}
