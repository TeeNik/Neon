#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIStateMachine.generated.h"

class UAIState;
struct FTimerHandle;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAIStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAIStateMachine();

	void NextState(UAIState* state);
	void EndTurn();
	void StartTurn();
	void SetAwake(bool value);
	FTimerHandle Timer;

protected:
	virtual void BeginPlay() override;

private:
	UAIState* CurrentState = NULL;
	bool isAwake;
	UFUNCTION()
	void EndTurnImpl();
};
