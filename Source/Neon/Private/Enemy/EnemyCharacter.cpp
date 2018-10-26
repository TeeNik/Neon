// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "LocationManager.h"
#include "NeonGameMode.h"
#include "NeonPlayerController.h"

AEnemyCharacter::AEnemyCharacter()
{
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
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
	EnergyComp->Initiative = 3;
}

void AEnemyCharacter::InitialMovement()
{
	SetActorLocation(FVector());
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* locationMan = GM->GetLocationManager();
}

void AEnemyCharacter::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void AEnemyCharacter::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void AEnemyCharacter::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{

	if(isInRange)
	{
		ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
		if(PC)
		{
			PC->NeonCharacter->GetWeaponComponent()->Shoot(MotionComp);
			PC->NeonCharacter->GetEnergyComponent()
		}
	}
}

void AEnemyCharacter::Deactivate_Implementation()
{

}

bool AEnemyCharacter::Highlight_Implementation(FString& AbilityName)
{
	GetMesh()->SetRenderCustomDepth(true);
	isInRange = true;
	return true;
}



