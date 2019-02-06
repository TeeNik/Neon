#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "LocationManager.h"
#include "NeonGameMode.h"
#include "System/UtilsLibrary.h"
#include "System/GameStrings.h"
#include "Ability/Ability.h"
#include "Commands/ShootCommand.h"
#include "Commands/OverloadCommand.h"
#include "Components/StaticMeshComponent.h"
#include "Components/MotionComponent.h"
#include "Components/WeaponComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/HealthComponent.h"
#include "Components/EnergyComponent.h"
#include "AI/AIStateMachine.h"
#include "Components/AbilityComponent.h"
#include "WorldActors/GridBase.h"
#include "Action/ActionTableData.h"
#include "Engine/World.h"
#include "System/TurnManager.h"

AEnemyCharacter::AEnemyCharacter()
{
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	AbilityComp = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbilityComponent"));
	AI = CreateDefaultSubobject<UAIStateMachine>(TEXT("AIStateMachine"));
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

	EnergyComp->OnStartTurn.AddUFunction(this, "OnStartTurn");
}

void AEnemyCharacter::InitialMovement()
{
	SetActorLocation(FVector());
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* locationMan = GM->GetLocationManager();
}

void AEnemyCharacter::OnBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, HighlightMaterial);
	}
}

void AEnemyCharacter::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, DefaultMaterial);
	}
}

void AEnemyCharacter::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{

	if(isInRange)
	{
		Command* command = NULL;
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if (EC) {
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Data->Name;

			//TODO
			if (actionComp->ActiveAction->Data->ObjectTag != "Enemy") return;
			GM->OnPlayerAbilityCall.Broadcast(this);
			EC->SpendEnergy(actionComp->ActiveAction->Data->Cost);
		}
	}
}

void AEnemyCharacter::Deactivate()
{
	isInRange = false;
	SelectionCircle->SetMaterial(0, DefaultMaterial);
}

bool AEnemyCharacter::Highlight(FString& AbilityName)
{
	isInRange = true;
	return true;
}

void AEnemyCharacter::HideCircle()
{
	SelectionCircle->SetVisibility(false);
}

void AEnemyCharacter::OnStartTurn()
{
	AI->StartTurn();
}
