#pragma once
#include "CoreMinimal.h"
#include "AIState.h"
#include "MovementState.generated.h"

class UAIStateMachine;

UCLASS()
class NEON_API UMovementState : public UAIState
{
	GENERATED_BODY()

public:
	UMovementState();
	UMovementState(UAIStateMachine*);
	virtual ~UMovementState();
	virtual void Execute();


};
