#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "ActivateTurretAbility.generated.h"

UCLASS()
class NEON_API UActivateTurretAbility : public UAbility
{
	GENERATED_BODY()
	
public:
	virtual void Execute(AActor*, AActor*) override;
	
	
};
