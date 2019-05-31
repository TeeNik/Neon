#include "IdleState.h"
#include "AIStateMachine.h"
#include "AbilityComponent.h"
#include "Ability.h"
#include "Action/ActionTableData.h"
#include "GameFramework/Actor.h"
#include "NeonPlayerController.h"
#include "UtilsLibrary.h"
#include "NeonCharacter.h"
#include "ShootState.h"
#include "MovementState.h"
#include "Engine/World.h"

UIdleState::UIdleState()
{
	Name = "IdleState";
}

void UIdleState::Execute()
{
	FString name = TEXT("Shoot");
	UAbilityComponent* abilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
	UAbility* shootAbility = abilityComp->FindAbilityByName(name);

	//TODO
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(AI->GetWorld()->GetFirstPlayerController());
	ANeonCharacter* player = PC->NeonCharacter;
	player->GetAbilityComponent();
	float dist = FVector::Dist(player->GetActorLocation(), AI->GetOwner()->GetActorLocation());
	float shootRange = shootAbility->Data->Range;

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
		UAIState* state = NewObject<UShootState>(this, UShootState::StaticClass());
		state->Init(AI);
		AI->NextState(state);
	}

	/*if (dist < shootRange) {
		AI->SetAwake(true);
		FName tag = TEXT("Player");
		UAIState* state = NewObject<UShootState>(this, UShootState::StaticClass());
		AI->NextState(state);
	}*/
	else {
		UAIState* state = NewObject<UMovementState>(this, UMovementState::StaticClass());
		AI->NextState(state);
	}
}