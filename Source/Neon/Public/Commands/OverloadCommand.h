#pragma once
#include "Commands/Command.h"
#include "CoreMinimal.h"

class UHealthComponent;

class NEON_API OverloadCommand : public Command
{
public:
	OverloadCommand(UHealthComponent* health, int& value);
	~OverloadCommand();
	virtual void Execute();

private:
	UHealthComponent * HealthComponent;
	int Value;
};
