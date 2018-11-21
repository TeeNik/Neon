#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "LocationManager.h"
#include "NeonGameMode.h"
#include "System/UtilsLibrary.h"
#include "System/GameStrings.h"
#include "NeonPlayerController.h"
#include "Commands/ShootCommand.h"
#include "Commands/OverloadCommand.h"
#include "Components/StaticMeshComponent.h"
#include "Components/MotionComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/HealthComponent.h"
#include "Components/EnergyComponent.h"
#include "Components/AbilityComponent.h"
#include "Components/WeaponComponent.h"
#include "WorldActors/GridBase.h"
#include "Action/ActionTableData.h"
#include "Engine/World.h"

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
	/*capsule->OnBeginCursorOver.AddDynamic(this, &AEnemyCharacter::OnBeginCursorOver);
	capsule->OnEndCursorOver.AddDynamic(this, &AEnemyCharacter::OnEndCursorOver);
	capsule->OnClicked.AddDynamic(this, &AEnemyCharacter::OnClicked);*/

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

/*void AEnemyCharacter::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
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
			if (actionName.Equals(UGameStrings::ShootAction))
			{
				UWeaponComponent* weaponComp = UUtilsLibrary::GetRelativeComponent<UWeaponComponent>(EC);
				command = new ShootCommand(weaponComp, MotionComp);
			}
			else if(actionName.Equals(UGameStrings::OverloadAction))
			{
				int value = 50;
				command = new OverloadCommand(HealthComp, value);
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
}*/

void AEnemyCharacter::HideCircle()
{
	SelectionCircle->SetVisibility(false);
}