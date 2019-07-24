#include "MovementState.h"
#include "AIStateMachine.h"
#include "NeonPlayerController.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "UtilsLibrary.h"
#include "Ability.h"
#include "Components/AbilityComponent.h"
#include "NeonCharacter.h"
#include "GridBase.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GridLocationComponent.h"
#include "ActionTableData.h"
#include "IdleState.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"

UMovementState::UMovementState()
{
    Name = "MovementState";
}

void UMovementState::Execute()
{
    ANeonPlayerController* PC = Cast<ANeonPlayerController>(AI->GetWorld()->GetFirstPlayerController());
    ANeonCharacter* player = PC->NeonCharacter;
    UAbilityComponent* abilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
    UMotionComponent* motionComp = UUtilsLibrary::GetRelativeComponent<UMotionComponent>(AI);
	FVector targetLoc = player->GetActorLocation();
	
	TSet<AGridBase*> gridAroundTarget = GetGridAround(player->GetAbilityComponent());
	TSet<AGridBase*> gridAroundAI = GetGridAround(abilityComp);

	TSet<AGridBase*> intersection = gridAroundAI.Intersect(gridAroundTarget);

	intersection.Sort([&](AGridBase& A, AGridBase& B) {
		float distA = FVector::Dist(targetLoc, A.GetActorLocation());
		float distB = FVector::Dist(targetLoc, B.GetActorLocation());

		return distA > distB;
	});

	if (intersection.Num() > 0) {
		TArray<AGridBase*> array = intersection.Array();
		AGridBase* grid = array[intersection.Num()/2];
		motionComp->MoveToGrid(grid);
	}
	//State ending is in the ANeonAIController
}

TSet<AGridBase*> UMovementState::GetGridAround(UAbilityComponent * abilityComp)
{
	FString shoot = "Shoot";
	FString move = "MoveTo";
	UAbility* shootAbility = abilityComp->FindAbilityByName(shoot);
	UAbility* moveAbility = abilityComp->FindAbilityByName(move);
	float shootRange = shootAbility->Data->Range;
	TArray<FHitResult> actorsAroundTarget = abilityComp->GetActorsInRange(shootRange);
	TSet<AGridBase*> gridAround;
	for (auto It = actorsAroundTarget.CreateIterator(); It; It++)
	{
		AActor* actor = It->GetActor();
		if (actor->ActorHasTag(moveAbility->Data->ObjectTag)) {
			AGridBase* grid = Cast<AGridBase>(actor);
			if (grid != NULL && grid->GetLocationComponent()->GetStatus() == GridLocationStatus::Empty && grid->GetLocationComponent()->State == GridBaseState::Down) {
				gridAround.Add(grid);
			}
		}
	}
	return gridAround;
}
