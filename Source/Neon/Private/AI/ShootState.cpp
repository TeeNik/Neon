
#include "ShootState.h"
#include "AI/AIStateMachine.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "Components/AbilityComponent.h"
#include "Ability/Ability.h"
#include "GameFramework/Actor.h"
#include "UtilsLibrary.h"

ShootState::ShootState(UAIStateMachine* ai, FName& targetTag) : AIState(ai)
{
	TargetTag = targetTag;
	Name = "ShootState";
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
		AActor* actor = It->GetActor();
		if (actor->ActorHasTag(TargetTag)) {
			AbilityComp->ActiveAction->Execute(AbilityComp->GetOwner(), actor);
			break;
		}
	}
	AI->EndTurn();
}
