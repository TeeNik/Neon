#pragma once
#include "CoreMinimal.h"
#include "AIState.h"
#include "MovementState.generated.h"

UCLASS()
class NEON_API UMovementState : public UAIState
{
	GENERATED_BODY()

public:
	UMovementState();
	virtual void Execute() override;


};
