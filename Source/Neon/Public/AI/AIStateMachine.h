#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AIState.h"
#include "AIStateMachine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAIStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAIStateMachine();

	void NextState(AIState& state);

protected:
	virtual void BeginPlay() override;

private:
	AIState CurrentState;
};
