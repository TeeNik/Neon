// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

AWeapon::AWeapon()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::Shoot(FRotator& rotation, FName& targetTag, int32& dmg)
{
	FVector start = MeshComp->GetSocketLocation("Muzzle");
	AWeaponProjectile* projectile = GetWorld()->SpawnActor<AWeaponProjectile>(Projectile, start, rotation/* + FRotator(25,0,0)*/);
	GLog->Log(FString::FromInt(dmg));
	projectile->Init(targetTag, dmg);
}
