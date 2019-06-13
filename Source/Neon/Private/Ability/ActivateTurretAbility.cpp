#include "ActivateTurretAbility.h"
#include "Enemy/Turret.h"

void UActivateTurretAbility::Execute(AActor * owner, AActor * target)
{
	ATurret* turret = Cast<ATurret>(target);
	turret->ActivateByPlayer();
	Super::Execute(owner, target);
}