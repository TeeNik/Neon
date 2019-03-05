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
	virtual ~UAIState();
	virtual void Execute();
	void Init(UAIStateMachine* ai);
	FString Name;
	UAIStateMachine * AI;
};
