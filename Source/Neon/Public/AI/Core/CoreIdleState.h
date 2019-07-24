#pragma once

#include "CoreMinimal.h"
#include "AI/AIState.h"
#include "CoreIdleState.generated.h"

UCLASS()
class NEON_API UCoreIdleState : public UAIState
{
	GENERATED_BODY()

public:
	UCoreIdleState();
	virtual void Execute() override;
	
};
