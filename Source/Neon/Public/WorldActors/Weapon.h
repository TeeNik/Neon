// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class AWeaponProjectile;
class UStaticMeshComponent;

UCLASS()
class NEON_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	FORCEINLINE int8 GetDamage() { return Damage; }
	FORCEINLINE int8 GetAccuracy() { return Accuracy; }

	void Shoot(FRotator& rotation, FName& targetTag, int32& dmg);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int8 Damage;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int8 Accuracy;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AWeaponProjectile> Projectile;
};
