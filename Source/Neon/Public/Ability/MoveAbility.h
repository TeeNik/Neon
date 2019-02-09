
#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "MoveAbility.generated.h"

UCLASS()
class NEON_API UMoveAbility : public UAbility
{
	GENERATED_BODY()
	
public:
	virtual void Execute(AActor*, AActor*) override;
	
	
};