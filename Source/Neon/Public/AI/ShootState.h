#pragma once

#include "CoreMinimal.h"
#include "AI/AIState.h"

class UWeaponComponent;
class UAbilityComponent;
class UAIStateMachine;

class NEON_API ShootState : AIState
{
public:
	ShootState(UAIStateMachine* ai, FName& targetTag, UWeaponComponent* weaponComponent, UAbilityComponent* abilityComp);
	virtual ~ShootState();
	virtual void Execute();
private:
	FName TargetTag;
	UWeaponComponent* WeaponComp;
	UAbilityComponent* AbilityComp;
};
