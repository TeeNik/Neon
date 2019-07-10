// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "System/UtilsLibrary.h"
#include "Components/MotionComponent.h"
#include "Components/WeaponComponent.h"
#include "System/LocationManager.h"
#include "NeonGameMode.h"
#include "Engine/World.h"
#include "System/InfoWidgetManager.h"

UHealthComponent::UHealthComponent()
{

}



void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth-40;
	CurrentShield = MaxShield;

	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->GetInfoWidgetManager()->RegisterEvent(this);
	}
}

Direction UHealthComponent::GetDefenceValue()
{
	UMotionComponent* motion = UUtilsLibrary::GetRelativeComponent<UMotionComponent>(this);
	auto GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if (motion && GM)
	{
		auto pos = motion->GetPosition();
		return GM->GetLocationManager()->GetCoverInfo(pos);
	}
	return Direction();
}

void UHealthComponent::TakeDamage(int& damage)
{
	if (damage > CurrentShield) {
		damage -= CurrentShield;
		CurrentShield = 0;
	}
	else {
		CurrentShield -= damage;
		return;
	}

	CurrentHealth -= damage;
	if (CurrentHealth <= 0)
	{
		Death.Broadcast();
	}
	else {
		OnDataUpdate.Broadcast(this);
	}
}

void UHealthComponent::AddShield(int& value)
{
	CurrentShield += value;
	if(CurrentShield > MaxShield)
	{
		CurrentShield = MaxShield;
	}
}

void UHealthComponent::DamageShield(int& value)
{
	CurrentShield -= value;
	if(CurrentShield < 0)
	{
		CurrentShield = 0;
	}
}
