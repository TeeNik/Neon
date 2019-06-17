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

	UPROPERTY()
	FTimerHandle Timer;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAIState*> FirstState;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	UAIState* CurrentState = NULL;
	UFUNCTION()
	void EndTurnImpl();
};
