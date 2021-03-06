#pragma once

#include "CoreMinimal.h"
#include "Ability/Ability.h"
#include "ShootAbility.generated.h"

UCLASS()
class NEON_API UShootAbility : public UAbility
{
	GENERATED_BODY()
	
public:
	virtual void Execute(AActor* owner, AActor* target) override;
	
};
