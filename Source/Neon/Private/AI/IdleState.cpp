#include "IdleState.h"
#include "AIStateMachine.h"
#include "AbilityComponent.h"
#include "GameFramework/Actor.h"

IdleState::IdleState(UAIStateMachine* ai, UAbilityComponent* abilityComp) : AIState(ai)
{
	AbilityComp = abilityComp;
}

IdleState::~IdleState()
{
}

void IdleState::Execute()
{
	FString name = TEXT("Shoot");
	TArray<FHitResult> actors = AbilityComp->GetActorsInRange(name);
	bool hasPlayerInRange = false;
	for (auto It = actors.CreateIterator(); It; It++)
	{
		auto actor = It->Actor;
		if (actor->ActorHasTag(TEXT("Player"))) {
			hasPlayerInRange = true;
			break;
		}
	}
	AI->EndTurn();
}
