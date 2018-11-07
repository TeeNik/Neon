#include "ShootCommand.h"

ShootCommand::ShootCommand(UWeaponComponent* weaponComp, UMotionComponent* motionComp)
{
	WeaponComp = weaponComp;
	MotionComp = motionComp;
}

ShootCommand::~ShootCommand()
{
}

void ShootCommand::Execute()
{
	GLog->Log("Execute shoot");
}
