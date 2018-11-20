#include "Turret.h"
#include "Components/AbilityComponent.h"
#include "Components/HealthComponent.h"
#include "Components/MotionComponent.h"
#include "Components/EnergyComponent.h"
#include "System/UtilsLibrary.h"
#include "GameStrings.h"
#include "Components/StaticMeshComponent.h"
#include "Action/ActionTableData.h"
#include "NeonGameMode.h"

ATurret::ATurret()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	SelectionCircle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionCircle"));
	SelectionCircle->SetupAttachment(RootComponent);

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
	MeshComp->OnBeginCursorOver.AddDynamic(this, &ATurret::OnBeginCursorOver);
	MeshComp->OnEndCursorOver.AddDynamic(this, &ATurret::OnEndCursorOver);
	EnergyComp->OnStartTurn.AddUFunction(this, "ExecuteTurn");
}

void ATurret::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, HighlightMaterial);
	}
}

void ATurret::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, DefaultMaterial);
	}
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
			if (actionName == UGameStrings::ActivateAction)
			{
				ActivateByPlayer();
			}
			EC->SpendEnergy(actionComp->ActiveAction->Cost);
		}
		SelectionCircle->SetMaterial(0, DefaultMaterial);
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
	DefaultMaterial = GreenCircle;
	MeshComp->SetMaterial(1, PlayerMaterial);
	MeshComp->SetMaterial(4, PlayerMaterial);
}

void ATurret::ActivateByEnemy()
{
	Status = TurretStatus::EnemyTurret;
	DefaultMaterial = RedCircle;
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
