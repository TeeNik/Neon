#pragma once
#include "CoreMinimal.h"

class AActor;
struct FActionTableData;

class NEON_API Ability
{
public:
	Ability();
	virtual ~Ability();
	virtual void Execute(AActor*, AActor*) = 0;

	int32 Cooldown;
	FActionTableData* Data;
};
