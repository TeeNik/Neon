#pragma once

#include "AI/AIState.h"
#include "CoreMinimal.h"

class AIState;
class UWeaponComponent;
class UAbilityComponent;

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
