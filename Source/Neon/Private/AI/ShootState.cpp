
#include "ShootState.h"
#include "AI/AIStateMachine.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "Components/AbilityComponent.h"
#include "GameFramework/Actor.h"

ShootState::ShootState(UAIStateMachine* ai, FName& targetTag, UWeaponComponent* weaponComp, UAbilityComponent* abilityComp) : AIState(ai)
{
	TargetTag = targetTag;
	WeaponComp = weaponComp;
	AbilityComp = abilityComp;
}

ShootState::~ShootState()
{
}

void ShootState::Execute()
{
	FString name = TEXT("Shoot");
	TArray<FHitResult> actors = AbilityComp->GetActorsInRange(name);
	for (auto It = actors.CreateIterator(); It; It++)
	{
		auto actor = It->Actor;
		if (actor->ActorHasTag(TargetTag)) {
			UMotionComponent* motionComp = Cast<UMotionComponent>(actor->GetComponentByClass(UMotionComponent::StaticClass()));
			WeaponComp->Shoot(motionComp);
			break;
		}
	}
}
