#include "ShootState.h"
#include "AI/AIStateMachine.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "Components/AbilityComponent.h"
#include "Ability/Ability.h"
#include "GameFramework/Actor.h"
#include "Action/ActionTableData.h"
#include "UtilsLibrary.h"

UShootState::UShootState()
{
	Name = "ShootState";
}

void UShootState::Execute()
{
	UWeaponComponent* WeaponComp = UUtilsLibrary::GetRelativeComponent<UWeaponComponent>(AI);
	UAbilityComponent* AbilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
	FString name = TEXT("Shoot");
	AbilityComp->SetActiveAction(name);
	TArray<FHitResult> actors = AbilityComp->GetActorsInRange(AbilityComp->ActiveAction->Data->Range);
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
