#include "AbilityManager.h"
#include "Ability/Ability.h"

UAbilityManager::UAbilityManager()
{

}

Ability * UAbilityManager::GetAbility()
{
	return nullptr;
}

void UAbilityManager::BeginDestroy()
{
	Super::BeginDestroy();
	for (int i = 0; i < abilities.Num(); ++i) {
		delete abilities[i];
	}
}

void UAbilityManager::BeginPlay()
{
	Super::BeginPlay();
}