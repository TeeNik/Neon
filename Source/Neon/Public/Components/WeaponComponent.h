// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldActors/Weapon.h"
#include "Enemy/EnemyCharacter.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	void Shoot(AEnemyCharacter* enemy);
	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	bool IsShooting;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TSubclassOf<AWeapon> WeaponClass;

	AWeapon* EquipedWeapon;
};
