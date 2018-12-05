#include "IdleState.h"
#include "AIStateMachine.h"
#include "AbilityComponent.h"
#include "GameFramework/Actor.h"
#include "UtilsLibrary.h"
#include "ShootState.h"

IdleState::IdleState(UAIStateMachine* ai) : AIState(ai)
{
}

IdleState::~IdleState()
{
}

void IdleState::Execute()
{
	FString name = TEXT("Shoot");
	UAbilityComponent* abilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
	TArray<FHitResult> actors = abilityComp->GetActorsInRange(name);
	bool hasPlayerInRange = false;
	for (auto It = actors.CreateIterator(); It; It++)
	{
		auto actor = It->Actor;
		if (actor->ActorHasTag(TEXT("Player"))) {
			hasPlayerInRange = true;
			break;
		}
	}
	if (hasPlayerInRange) {
		AI->SetAwake(true);
		FName tag = TEXT("Player");
		AI->NextState(new ShootState(AI, tag));
		GLog->Log("Awake");
	}
	else {
		AI->EndTurn();
		GLog->Log("Idling");

	}
}
