#pragma once
#include "CoreMinimal.h"
#include "AIState.generated.h"

class UAIStateMachine;

UCLASS()
class NEON_API UAIState : public UObject
{
	GENERATED_BODY()

public:
	UAIState();
	UAIState(UAIStateMachine* ai);
	virtual ~UAIState();
	virtual void Execute();

	FString Name;
	UAIStateMachine * AI;
};
