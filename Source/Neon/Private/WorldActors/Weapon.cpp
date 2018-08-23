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
