#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "CoverInfoAbility.generated.h"


UCLASS()
class NEON_API UCoverInfoAbility : public UAbility
{
	GENERATED_BODY()
	
public:
    virtual void Execute(AActor*, AActor*) override;
};
