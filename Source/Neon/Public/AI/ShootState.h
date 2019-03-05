#pragma once

#include "CoreMinimal.h"
#include "AI/AIState.h"
#include "ShootState.generated.h"

class UAIStateMachine;

UCLASS()
class NEON_API UShootState : public UAIState
{
	GENERATED_BODY()

public:
	UShootState();
	virtual ~UShootState();
	virtual void Execute();
private:
	FName TargetTag;
};
