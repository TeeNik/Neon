#pragma once
#include "AI/AIState.h"
#include "CoreMinimal.h"


class NEON_API ShootState : AIState
{
public:
	ShootState();
	~ShootState();
	virtual void Execute();
};
