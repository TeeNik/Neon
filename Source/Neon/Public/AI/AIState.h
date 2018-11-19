#pragma once
#include "CoreMinimal.h"

class UAIStateMachine;

class NEON_API AIState
{
public:
	AIState(UAIStateMachine* ai);
	virtual ~AIState();
	virtual void Execute();

private:
	UAIStateMachine * AI;
};
