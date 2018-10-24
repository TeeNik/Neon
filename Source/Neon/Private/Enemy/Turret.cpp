// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Components/AbilityComponent.h"
#include "Components/MotionComponent.h"
#include "System/UtilsLibrary.h"


ATurret::ATurret()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//RootComponent = MeshComp;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
	AbilityComp = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbilityComponent"));

	Status = TurretStatus::DisableTurret;
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComp->OnClicked.AddDynamic(this, &ATurret::OnClicked);
	EnergyComp->OnStartTurn.AddUFunction(this, "ExecuteTurn");
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
				ActivateByPlayer();
			}
			EC->SpendEnergy(actionComp->ActiveAction->Cost);
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

	MeshComp->SetRenderCustomDepth(true);
	isInRange = true;
	return true;
}

void ATurret::ActivateByPlayer()
{
	Status = TurretStatus::PlayerTurret;
	MeshComp->SetMaterial(1, PlayerMaterial);
	MeshComp->SetMaterial(4, PlayerMaterial);
}

void ATurret::ActivateByEnemy()
{
	Status = TurretStatus::EnemyTurret;
	MeshComp->SetMaterial(1, EnemyMaterial);
	MeshComp->SetMaterial(4, EnemyMaterial);
}

void ATurret::ExecuteTurn()
{
	if (Status != TurretStatus::DisableTurret) {
		Shoot();
	}
	EnergyComp->EndTurn();
}

void ATurret::Shoot()
{
	FString name = TEXT("Shoot");
	TArray<FHitResult> actors = AbilityComp->GetActorsInRange(name);
	FName targetTag = Status == TurretStatus::PlayerTurret ? TEXT("Enemy") : TEXT("Player");
	for (auto It = actors.CreateIterator(); It; It++)
	{
		auto actor = It->Actor;
		if (actor->ActorHasTag(targetTag)) {
			UMotionComponent* motionComp = Cast<UMotionComponent>(actor->GetComponentByClass(UMotionComponent::StaticClass()));
			WeaponComp->Shoot(motionComp);
			break;
		}
	}
}
