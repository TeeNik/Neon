#pragma once

#include "CoreMinimal.h"

class Command;
struct FActionTableData;

class NEON_API Ability
{
public:
	Ability();
	~Ability();

	Command* Command;
	int32 Cooldown;
	FActionTableData* Data;
};
