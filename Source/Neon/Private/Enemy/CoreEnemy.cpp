#include "CoreEnemy.h"
#include "EnergyComponent.h"
#include "HealthComponent.h"
#include "AbilityComponent.h"
#include "AI/AIStateMachine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "AI/Core/CoreIdleState.h"
#include "NeonGameMode.h"
#include "UtilsLibrary.h"

ACoreEnemy::ACoreEnemy()
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Capsule;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
	AbilityComp = CreateDefaultSubobject<UAbilityComponent>(TEXT("AbilityComponent"));
	AI = CreateDefaultSubobject<UAIStateMachine>(TEXT("AIStateMachine"));
	AI->FirstState = UCoreIdleState::StaticClass();
	EnergyComp->Initiative = 3;
	SelectionCircle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SelectionCircle"));
	SelectionCircle->SetupAttachment(RootComponent);
}

void ACoreEnemy::BeginPlay()
{
	Super::BeginPlay();

	Capsule->OnBeginCursorOver.AddDynamic(this, &ACoreEnemy::OnBeginCursorOver);
	Capsule->OnEndCursorOver.AddDynamic(this, &ACoreEnemy::OnEndCursorOver);
	Capsule->OnClicked.AddDynamic(this, &ACoreEnemy::OnClicked);

	EnergyComp->OnStartTurn.AddUFunction(this, "OnStartTurn");
}

void ACoreEnemy::OnBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, HighlightMaterial);
	}
}

void ACoreEnemy::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, DefaultMaterial);
	}
}

void ACoreEnemy::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{

	if (isInRange)
	{
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if (EC) {
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Data->Name;

			//TODO
			if (actionComp->ActiveAction->Data->ObjectTag != "Enemy") return;
			GM->OnPlayerAbilityCall.Broadcast(this);
		}
	}
}

void ACoreEnemy::Deactivate()
{
	isInRange = false;
	SelectionCircle->SetMaterial(0, DefaultMaterial);
}

bool ACoreEnemy::Highlight(FString& AbilityName)
{
	isInRange = true;
	return true;
}

void ACoreEnemy::HideCircle()
{
	SelectionCircle->SetVisibility(false);
}

void ACoreEnemy::OnStartTurn()
{
	AI->StartTurn();
}