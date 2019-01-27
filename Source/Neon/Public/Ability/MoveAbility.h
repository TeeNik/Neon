#pragma once
#include "Ability/Ability.h"
#include "CoreMinimal.h"

class Ability;
class AActor;

class NEON_API MoveAbility : public Ability
{
public:
	MoveAbility();
	~MoveAbility();
	virtual void Execute(AActor*, AActor*);
};
