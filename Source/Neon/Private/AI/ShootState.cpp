
#include "ShootState.h"
#include "AI/AIStateMachine.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "Components/AbilityComponent.h"
#include "GameFramework/Actor.h"
#include "UtilsLibrary.h"

ShootState::ShootState(UAIStateMachine* ai, FName& targetTag) : AIState(ai)
{
	TargetTag = targetTag;
}

ShootState::~ShootState()
{
}

void ShootState::Execute()
{
	UWeaponComponent* WeaponComp = UUtilsLibrary::GetRelativeComponent<UWeaponComponent>(AI);
	UAbilityComponent* AbilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
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
	AI->EndTurn();
}
