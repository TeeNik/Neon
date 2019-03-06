#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "LowerGridAbility.generated.h"

UCLASS()
class NEON_API ULowerGridAbility : public UAbility
{
	GENERATED_BODY()

public:
    virtual void Execute(AActor*, AActor*) override;

};
