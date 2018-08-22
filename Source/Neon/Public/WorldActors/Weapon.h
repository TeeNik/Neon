// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class NEON_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	float GetDamage() { return Damage; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float Damage;
	
};
