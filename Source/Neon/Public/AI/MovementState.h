#pragma once
#include "AIState.h"
#include "CoreMinimal.h"

class UAIStateMachine;

class NEON_API MovementState : AIState
{
public:
	MovementState(UAIStateMachine*);
	virtual ~MovementState();
	virtual void Execute();


};
