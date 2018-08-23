// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "NeonPlayerController.h"

AEnemyCharacter::AEnemyCharacter()
{
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
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
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

