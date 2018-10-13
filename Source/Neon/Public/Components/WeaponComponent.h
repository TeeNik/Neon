// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldActors/Weapon.h"
#include "WorldActors/GridBase.h"
#include "Components/MotionComponent.h"
#include "WeaponComponent.generated.h"


struct Direction
{
	bool Left;
	bool Up;
	bool Right;
	bool Down;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	void Shoot(UMotionComponent* enemy);
	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	bool IsShooting;

	void FactorDamage(float factor);

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TSubclassOf<AWeapon> WeaponClass;

	AWeapon* EquipedWeapon;

private:
	Direction CheckDirection(AGridBase* self, AGridBase* target);
};