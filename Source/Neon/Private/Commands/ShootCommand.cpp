#include "ShootCommand.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"

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
	WeaponComp->Shoot(MotionComp);
}
