#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "OverloadAbility.generated.h"

UCLASS()
class NEON_API UOverloadAbility : public UAbility
{
	GENERATED_BODY()
	
public:
	virtual void Execute(AActor*, AActor*) override;

	
	
};