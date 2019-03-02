#include "OverloadAbility.h"
#include "HealthComponent.h"
#include "System/UtilsLibrary.h"

void UOverloadAbility::Execute(AActor * owner, AActor * target)
{
	UHealthComponent* health = UUtilsLibrary::GetComponentByClass<UHealthComponent>(target);
	int damage = 50;
	health->DamageShield(damage);
	Super::Execute(owner, target);
}



