#pragma once
#include "CoreMinimal.h"
#include "AIState.h"
#include "MovementState.generated.h"

class AGridBase;
class UAbilityComponent;

UCLASS()
class NEON_API UMovementState : public UAIState
{
	GENERATED_BODY()

public:
	UMovementState();
	virtual void Execute() override;

private:
	TSet<AGridBase*> GetGridAround(UAbilityComponent* abilityComp);
};
