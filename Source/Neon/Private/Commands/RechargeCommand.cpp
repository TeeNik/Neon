#include "RechargeCommand.h"

RechargeCommand::RechargeCommand(UHealthComponent* health, int& value)
{
	HealthComponent = health;
	Value = value;
}

RechargeCommand::~RechargeCommand()
{
}

void RechargeCommand::Execute()
{
	HealthComponent->AddShield(Value);
}
