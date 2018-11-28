#pragma once
#include "AIState.h"
#include "CoreMinimal.h"

class UAIStateMachine;
class UAbilityComponent;

class NEON_API IdleState : AIState
{
public:
	IdleState(UAIStateMachine*, UAbilityComponent*);
	virtual ~IdleState();
	virtual void Execute();

private:
	UAbilityComponent * AbilityComp;
};
