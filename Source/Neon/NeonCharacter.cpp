#include "NeonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NeonPlayerController.h"
#include "NeonGameMode.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Ability/Ability.h"
#include "GameStrings.h"
#include "Components/EnergyComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/MotionComponent.h"
#include "Components/AbilityComponent.h"
#include "Components/HealthComponent.h"
#include "Components/WeaponComponent.h"
#include "Action/ActionTableData.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UI/ActionWidget.h"

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
	EnergyComp->Initiative = 10;

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
	EnergyComp->OnSpendEnergy.AddUFunction(this, "OnSpendEnergy");
	WeaponComp->Init(EnergyComp->OnEndTurn);
	UCapsuleComponent* capsule = GetCapsuleComponent();
	capsule->OnBeginCursorOver.AddDynamic(this, &ANeonCharacter::OnBeginCursorOver);
	capsule->OnEndCursorOver.AddDynamic(this, &ANeonCharacter::OnEndCursorOver);
	capsule->OnClicked.AddDynamic(this, &ANeonCharacter::OnClicked);
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	GM->OnPlayerAbilityCall.AddUFunction(this, "OnPlayerActionCall");
}

void ANeonCharacter::OnBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, HighlightMaterial);
	}
}

void ANeonCharacter::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (isInRange) {
		SelectionCircle->SetMaterial(0, DefaultMaterial);
	}
}

void ANeonCharacter::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" &&isInRange)
	{
		/*FString name = AbilityComp->ActiveAction->Name;
		if (name.Equals(UGameStrings::DamageBustAction)) {
			float bust = 1.5f;
			WeaponComp->BustDamage(bust);
		}
		else if (name.Equals(UGameStrings::AccuranceBustAction)) {
			int8 bonus = 20;
			WeaponComp->BustAccuracy(bonus);
		}
		EnergyComp->SpendEnergy(AbilityComp->ActiveAction->Cost);*/
	}
}

void ANeonCharacter::Deactivate()
{

}

bool ANeonCharacter::Highlight(FString& AbilityName)
{
	isInRange = true;
	return true;
}

void ANeonCharacter::OnPlayerActionCall(AActor* target)
{
	AbilityComp->ActiveAction->Execute(this, target);
}

void ANeonCharacter::OnSpendEnergy(int current, int value)
{
	AbilityComp->HideAbilityRange();
}
