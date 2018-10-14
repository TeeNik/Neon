// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "System/UtilsLibrary.h"
#include "Components/MotionComponent.h"
#include "Components/WeaponComponent.h"
#include "NeonGameMode.h"

UHealthComponent::UHealthComponent()
{

}

Direction UHealthComponent::GetDefenceValue()
{
	UMotionComponent* motion = UUtilsLibrary::GetRelativeComponent<UMotionComponent>(this);
	auto GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	if(motion && GM)
	{
		auto pos = motion->GetPosition();
		return GM->GetLocationManager()->GetCoverInfo(pos);
	}
	return Direction();
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth-40;
}

void UHealthComponent::Death()
{
	GetOwner()->Destroy();
}

void UHealthComponent::TakeDamage(float damage)
{
	CurrentHealth -= damage;
	if (CurrentHealth <= 0) Death();
}
