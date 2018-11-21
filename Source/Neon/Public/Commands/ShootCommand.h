#pragma once

#include "Commands/Command.h"
#include "CoreMinimal.h"

class UMotionComponent;
class UWeaponComponent;

class NEON_API ShootCommand : public Command
{
public:
	ShootCommand(UWeaponComponent* weaponComp, UMotionComponent* motionComp);
	~ShootCommand();
	virtual void Execute();

private:
	UWeaponComponent * WeaponComp;
	UMotionComponent* MotionComp;
};
