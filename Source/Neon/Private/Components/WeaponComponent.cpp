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

Direction UWeaponComponent::CheckDirection(AGridBase* self, AGridBase* target)
{
	Direction dir;
	int x = FMath::Abs(target->Column - self->Column);
	int rowTop = self->Row + x;
	int rowBot = self->Row - x;

	if (target->Column > self->Column && self->Column < rowTop && self->Column > rowBot)
	{
		GLog->Log("Right");
	}
	if (target->Column < self->Column && self->Column < rowTop && self->Column > rowBot)
	{
		GLog->Log("Left");
	}

	int y = FMath::Abs(target->Row - self->Row);
	int colRight = self->Column + x;
	int colLeft = self->Column - x;

	if (target->Row > self->Row && self->Row < colRight && self->Row > colLeft)
	{
		GLog->Log("Top");
	}
	if (target->Row < self->Row && self->Row < colRight && self->Row > colLeft)
	{
		GLog->Log("Bottom");
	}

	return dir;
}

void UWeaponComponent::Shoot(AEnemyCharacter* enemy)
{
	FVector direction = enemy->GetActorLocation() - GetOwner()->GetActorLocation();
	direction.Z = 0;
	const FRotator playerRot = FRotationMatrix::MakeFromX(direction).Rotator();
	GetOwner()->SetActorRotation(playerRot);
	
	IsShooting = true;
	enemy->GetHealthComponent()->TakeDamage(EquipedWeapon->GetDamage());
}



