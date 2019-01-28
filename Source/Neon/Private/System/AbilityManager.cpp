#include "AbilityManager.h"
#include "Action/ActionTableData.h"
#include "Ability/Ability.h"
#include "Ability/MoveAbility.h"
#include "System/ResourceManagerLibrary.h"
#include "System/ResourceManager.h"
#include "Engine/DataTable.h"

UAbilityManager::UAbilityManager()
{

}


void UAbilityManager::BeginPlay()
{
	Super::BeginPlay();

	UDataTable* dataTable = UResourceManagerLibrary::GetData()->ActionDataTable;
	dataTable->GetAllRows<FActionTableData>(TEXT(""), abilityDatas);

	InitAbility(new MoveAbility(), "MoveTo");
	//abilities.Add(new MoveAbility());
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

void UAbilityManager::InitAbility(Ability* ability, FString name)
{
	for (int i = 0; i < abilityDatas.Num(); ++i)
	{
		if (abilityDatas[i]->Name.Equals(name)) {
			ability->Data = abilityDatas[i];
			abilities.Add(ability);
			return;
		}
	}
}

void UAbilityManager::BeginDestroy()
{
	Super::BeginDestroy();
	for (int i = 0; i < abilities.Num(); ++i) {
		delete abilities[i];
	}
}
