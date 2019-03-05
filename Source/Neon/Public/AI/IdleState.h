#pragma once
#include "AIState.h"
#include "CoreMinimal.h"
#include "IdleState.generated.h"

UCLASS()
class NEON_API UIdleState : public UAIState
{
	GENERATED_BODY()

public:
	UIdleState();
	virtual void Execute() override;
};
