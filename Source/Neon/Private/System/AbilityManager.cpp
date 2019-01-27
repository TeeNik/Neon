#include "AbilityManager.h"
#include "Ability/Ability.h"
#include "Ability/MoveAbility.h"

UAbilityManager::UAbilityManager()
{

}

Ability * UAbilityManager::GetAbility(FString name)
{
	for (int i = 0; i < abilities.Num(); ++i) {
		GLog->Log(abilities[i]->Data->Name);
		if (abilities[i]->Data->Name.Equals(name)) {
			return abilities[i];
		}
	}
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

	abilities.Add(new MoveAbility());
}