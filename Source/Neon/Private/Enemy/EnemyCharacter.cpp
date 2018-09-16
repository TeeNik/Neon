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
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UCapsuleComponent* capsule = GetCapsuleComponent();
	capsule->OnBeginCursorOver.AddDynamic(this, &AEnemyCharacter::OnBeginCursorOver);
	capsule->OnEndCursorOver.AddDynamic(this, &AEnemyCharacter::OnEndCursorOver);
	capsule->OnClicked.AddDynamic(this, &AEnemyCharacter::OnClicked);

	FTimerHandle timer;
	GetWorld()->GetTimerManager().SetTimer(timer, this, &AEnemyCharacter::InitialMovement, 3, false);

	
}

void AEnemyCharacter::InitialMovement()
{
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	ULocationManager* locationMan = GM->GetLocationManager();
	MotionComp->MoveToGrid(locationMan->GridArray[2].Array[2]);
	Position = locationMan->GridArray[2].Array[2];
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
			PC->NeonCharacter->GetWeaponComponent()->Shoot(this);
		}
	}
}

void AEnemyCharacter::Deactivate_Implementation()
{

}

void AEnemyCharacter::Highlight_Implementation()
{
	GetMesh()->SetRenderCustomDepth(true);
	isInRange = true;
}



