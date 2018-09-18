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

	if (target->Column > self->Column && target->Column <= rowTop && target->Column >= rowBot)
	{
		dir.Right = true;
		GLog->Log("Right");
	}
	if (target->Column < self->Column && target->Column <= rowTop && target->Column >= rowBot)
	{
		dir.Left = true;
		GLog->Log("Left");
	}

	int y = FMath::Abs(target->Row - self->Row);
	int colRight = self->Column + y;
	int colLeft = self->Column - y;

	if (target->Row > self->Row && target->Row <= colRight && target->Row >= colLeft)
	{
		dir.Up = true;
		GLog->Log("Top");
	}
	if (target->Row < self->Row && target->Row <= colRight && target->Row >= colLeft)
	{
		dir.Down = true;
		GLog->Log("Bottom");
	}

	return dir;
}

void UWeaponComponent::Shoot(AEnemyCharacter* enemy)
{
	ANeonCharacter* character = Cast<ANeonCharacter>(GetOwner());
	CheckDirection(character->Position, enemy->Position);
	FVector direction = enemy->GetActorLocation() - GetOwner()->GetActorLocation();
	direction.Z = 0;
	const FRotator playerRot = FRotationMatrix::MakeFromX(direction).Rotator();
	GetOwner()->SetActorRotation(playerRot);
	
	IsShooting = true;
	enemy->GetHealthComponent()->TakeDamage(EquipedWeapon->GetDamage());
}



