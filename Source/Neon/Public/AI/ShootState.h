#pragma once

#include "CoreMinimal.h"
#include "AI/AIState.h"

class UAIStateMachine;

class NEON_API ShootState : public AIState
{
public:
	ShootState(UAIStateMachine* ai, FName& targetTag);
	virtual ~ShootState();
	virtual void Execute();
private:
	FName TargetTag;
};
