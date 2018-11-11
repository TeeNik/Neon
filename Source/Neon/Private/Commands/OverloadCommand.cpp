#include "OverloadCommand.h"

OverloadCommand::OverloadCommand(UHealthComponent* health, int& value)
{
	HealthComponent = health;
	Value = value;
}

OverloadCommand::~OverloadCommand()
{
}

void OverloadCommand::Execute()
{
	HealthComponent->DamageShield(Value);
}
