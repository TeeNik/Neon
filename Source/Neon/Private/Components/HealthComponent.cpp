// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{

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
