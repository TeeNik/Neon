#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIStateMachine.generated.h"

class AIState;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAIStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAIStateMachine();

	void NextState(AIState* state);
	void EndTurn();
	void StartTurn();
	void SetAwake(bool value);

protected:
	virtual void BeginPlay() override;

private:
	AIState* CurrentState = NULL;
	bool isAwake;
};
