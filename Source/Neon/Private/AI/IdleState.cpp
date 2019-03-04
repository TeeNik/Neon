#include "IdleState.h"
#include "AIStateMachine.h"
#include "AbilityComponent.h"
#include "Ability.h"
#include "Action/ActionTableData.h"
#include "GameFramework/Actor.h"
#include "UtilsLibrary.h"
#include "ShootState.h"

UIdleState::UIdleState(UAIStateMachine* ai) : UAIState(ai)
{
	Name = "IdleState";
}

UIdleState::UIdleState()
{

}

UIdleState::~UIdleState()
{
}

void UIdleState::Execute()
{
	FString name = TEXT("Shoot");
	UAbilityComponent* abilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
	UAbility* shootAbility = abilityComp->FindAbilityByName(name);
	TArray<FHitResult> actors = abilityComp->GetActorsInRange(shootAbility->Data->Range);
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
	}
	else {
		AI->EndTurn();
	}
}