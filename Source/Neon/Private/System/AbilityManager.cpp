#include "AbilityManager.h"
#include "Action/ActionTableData.h"
#include "Ability/Ability.h"
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
	TArray<FActionTableData*> abilityDatas;
	dataTable->GetAllRows<FActionTableData>(TEXT(""), abilityDatas);

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

void UAbilityManager::BeginDestroy()
{
	Super::BeginDestroy();
	for (int i = 0; i < abilities.Num(); ++i) {
		delete abilities[i];
	}
}
