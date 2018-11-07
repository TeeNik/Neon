#pragma once

#include "Commands/Command.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "CoreMinimal.h"

class NEON_API ShootCommand : Command
{
public:
	ShootCommand(UWeaponComponent* weaponComp, UMotionComponent* motionComp);
	~ShootCommand();
	virtual void Execute();

private:
	UWeaponComponent * WeaponComp;
	UMotionComponent* MotionComp;
};
