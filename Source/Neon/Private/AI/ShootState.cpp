
#include "ShootState.h"
#include "AI/AIStateMachine.h"
#include "Components/WeaponComponent.h"
#include "Components/AbilityComponent.h"

ShootState::ShootState(UAIStateMachine* ai, FName& targetTag, UWeaponComponent* weaponComponent, UAbilityComponent* abilityComp) : AIState(ai)
{

}

ShootState::~ShootState()
{
}

void ShootState::Execute()
{

}
