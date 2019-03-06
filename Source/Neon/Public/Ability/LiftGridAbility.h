#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "LiftGridAbility.generated.h"

UCLASS()
class NEON_API ULiftGridAbility : public UAbility
{
	GENERATED_BODY()

public:
    virtual void Execute(AActor*, AActor*) override;
};
