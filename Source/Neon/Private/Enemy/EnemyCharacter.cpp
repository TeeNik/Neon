// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{

}

void AEnemyCharacter::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void AEnemyCharacter::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void AEnemyCharacter::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{

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

