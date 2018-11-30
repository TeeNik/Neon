#pragma once
#include "AIState.h"
#include "CoreMinimal.h"

class UAIStateMachine;
class UAbilityComponent;

class NEON_API IdleState : public AIState
{
public:
	IdleState(UAIStateMachine*);
	virtual ~IdleState();
	virtual void Execute();

private:
	UAbilityComponent * AbilityComp;
};
