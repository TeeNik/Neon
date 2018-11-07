#pragma once

#include "CoreMinimal.h"

class NEON_API Command
{
public:
	Command();
	virtual ~Command();
	virtual void Execute() = 0;
};
