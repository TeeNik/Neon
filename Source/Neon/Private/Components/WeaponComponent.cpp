// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponComponent.h"
#include "NeonCharacter.h"
#include "System/UtilsLibrary.h"

UWeaponComponent::UWeaponComponent()
{
}


void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	if(WeaponClass)
	{
		EquipedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
		FAttachmentTransformRules attachRules(EAttachmentRule::SnapToTarget, true);
		ACharacter* character = Cast<ACharacter>(GetOwner());
		if (character)
		{
			EquipedWeapon->AttachToComponent(character->GetMesh(), attachRules, "WeaponSocket");
		}
	}
}

void UWeaponComponent::Init(OnEndTurnDelegate& onTurnEnd)
{
	onTurnEnd.AddUFunction(this, "OnTurnEnd");
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

void UWeaponComponent::Shoot(UMotionComponent* enemy)
{
	ANeonCharacter* character = Cast<ANeonCharacter>(GetOwner());
	UMotionComponent* self = UUtilsLibrary::GetRelativeComponent<UMotionComponent>(this);
	Direction shootDir = CheckDirection(self->GetPosition(), enemy->GetPosition());
	FVector direction = enemy->GetOwner()->GetActorLocation() - GetOwner()->GetActorLocation();
	direction.Z = 0;
	const FRotator playerRot = FRotationMatrix::MakeFromX(direction).Rotator();
	GetOwner()->SetActorRotation(playerRot);
	IsShooting = true;
	UHealthComponent* health = UUtilsLibrary::GetRelativeComponent<UHealthComponent>(enemy);

	Direction enemyCover = health->GetDefenceValue();
	int8 accuracy = EquipedWeapon->GetAccuracy();
	accuracy -= CalculateCover(shootDir, enemyCover);

	int8 chance = FMath::RandRange(0, 100);
	GLog->Log(FString::FromInt(chance));
	GLog->Log(FString::FromInt(accuracy));
	if (chance <= accuracy + AccuracyBuff) {
		GLog->Log("Success");
		health->TakeDamage(EquipedWeapon->GetDamage()*DamageBuff);
	}
	else {
		GLog->Log("Miss");
	}
}

void UWeaponComponent::BustDamage(float factor)
{
	DamageBuff = factor;
}

void UWeaponComponent::BustAccuracy(int8 factor)
{
	AccuracyBuff = factor;
}

int8 UWeaponComponent::CalculateCover(Direction& shootDir, Direction& enemyDef)
{
	int8 def = 30;

	if (shootDir.Left == true) {
		if (enemyDef.Left == false) {
			return 0;
		}
	}
	if (shootDir.Up == true) {
		if (enemyDef.Up == false)
			return 0;
	}
	if (shootDir.Right == true) {
		if (enemyDef.Right == false)
			return 0;
	}
	if (shootDir.Down == true) {
		if (enemyDef.Down == false)
			return 0;
	}

	return def;
}

void UWeaponComponent::OnTurnEnd()
{
	DamageBuff = 0;
	AccuracyBuff = 0;
}




