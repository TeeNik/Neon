#pragma once
#include "Commands/Command.h"
#include "Components/HealthComponent.h"
#include "CoreMinimal.h"

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
