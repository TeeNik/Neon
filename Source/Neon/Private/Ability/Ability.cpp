#include "Ability.h"
#include "EnergyComponent.h"
#include "UtilsLibrary.h"
#include "ActionTableData.h"
#include "GameFramework/Actor.h"

UAbility::UAbility()
{
}

UAbility::~UAbility()
{
	//TODO
	//delete Data;
}

void UAbility::Execute(AActor* owner, AActor*)
{
	UEnergyComponent* energy = UUtilsLibrary::GetComponentByClass<UEnergyComponent>(owner);
	energy->SpendEnergy(Data->Cost);
}

