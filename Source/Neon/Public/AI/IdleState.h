#pragma once
#include "AIState.h"
#include "CoreMinimal.h"
#include "IdleState.generated.h"

class UAIStateMachine;
class UAbilityComponent;

UCLASS()
class NEON_API UIdleState : public UAIState
{
	GENERATED_BODY()

public:
	UIdleState();
	UIdleState(UAIStateMachine*);
	virtual ~UIdleState();
	virtual void Execute();
};
