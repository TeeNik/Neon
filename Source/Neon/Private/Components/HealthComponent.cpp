// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

void UHealthComponent::BeginPlay()
{
	CurrentHealth = MaxHealth;
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
