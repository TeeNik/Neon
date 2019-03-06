#include "AbilityManager.h"
#include "Action/ActionTableData.h"
#include "Ability/Ability.h"
#include "Ability/MoveAbility.h"
#include "Ability/ShootAbility.h"
#include "Ability/OverloadAbility.h"
#include "Ability/LiftGridAbility.h"
#include "Ability/LowerGridAbility.h"
#include "Ability/ActivateTurretAbility.h"
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
}

UAbility * UAbilityManager::GetAbility(FString name)
{
	UAbility* ability = NULL;

	if (name.Equals("MoveTo")) {
		ability = NewObject<UMoveAbility>(this, UMoveAbility::StaticClass());
	}
	else if (name.Equals("Shoot")) {
		ability = NewObject<UShootAbility>(this, UShootAbility::StaticClass());
	}
	else if (name.Equals("ActivateTurret")) {
		ability = NewObject<UActivateTurretAbility>(this, UActivateTurretAbility::StaticClass());
	}
	else if (name.Equals("Overload")) {
		ability = NewObject<UOverloadAbility>(this, UOverloadAbility::StaticClass());
	}
    else if (name.Equals("Lift")) {
        ability = NewObject<ULiftGridAbility>(this, ULiftGridAbility::StaticClass());
    }
    else if (name.Equals("Lower")) {
        ability = NewObject<ULowerGridAbility>(this, ULowerGridAbility::StaticClass());
    }
	if (ability == NULL) return nullptr;
	InitAbility(ability, name);
	return ability;
}

void UAbilityManager::InitAbility(UAbility* ability, FString name)
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