// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"


ATurret::ATurret()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//RootComponent = MeshComp;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	WeaponComp = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));
	MotionComp = CreateDefaultSubobject<UMotionComponent>(TEXT("MotionComponent"));
	EnergyComp = CreateDefaultSubobject<UEnergyComponent>(TEXT("EnergyComponent"));
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATurret::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void ATurret::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{

}

void ATurret::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" && isInRange)
	{
	}
}

void ATurret::Deactivate_Implementation()
{

}

bool ATurret::Highlight_Implementation(FString& AbilityName)
{
	if (AbilityName == ActivateAbility && Status != Disable)
		return false;

	isInRange = true;
	return true;
}
