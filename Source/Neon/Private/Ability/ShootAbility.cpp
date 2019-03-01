#include "ShootAbility.h"
#include "System/UtilsLibrary.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "GameFramework/Actor.h"

void UShootAbility::Execute(AActor* owner, AActor* target)
{
	UWeaponComponent* weapon = UUtilsLibrary::GetComponentByClass<UWeaponComponent>(owner);
	UMotionComponent* motion = UUtilsLibrary::GetComponentByClass<UMotionComponent>(target);
	weapon->Shoot(motion);
	Super::Execute(owner, target);
}
