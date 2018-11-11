#pragma once
#include "Commands/Command.h"
#include "CoreMinimal.h"
#include "HealthComponent.h"

class NEON_API RechargeCommand : public Command
{
public:
	RechargeCommand(UHealthComponent* health, int& value);
	~RechargeCommand();
	virtual void Execute();
private:
	UHealthComponent * HealthComponent;
	int Value;
};
