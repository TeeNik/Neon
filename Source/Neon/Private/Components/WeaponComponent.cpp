// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponComponent.h"
#include "NeonCharacter.h"
UWeaponComponent::UWeaponComponent()
{
}


void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	if(WeaponClass)
	{
		ANeonCharacter* owner = Cast<ANeonCharacter>(GetOwner());
		if(owner)
		{
			EquipedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, owner->GetActorLocation(), owner->GetActorRotation());
			FAttachmentTransformRules attachRules(EAttachmentRule::SnapToTarget, true);
			EquipedWeapon->AttachToComponent(owner->GetMesh(), attachRules, "WeaponSocket");
		}	
	}

}

void UWeaponComponent::Shoot(AEnemyCharacter* enemy)
{
	FVector direction = enemy->GetActorLocation() - GetOwner()->GetActorLocation();
	direction.Z = 0;
	const FRotator playerRot = FRotationMatrix::MakeFromX(direction).Rotator();
	GetOwner()->SetActorRotation(playerRot);
}



