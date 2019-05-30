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

UMovementState::UMovementState()
{
    Name = "MovementState";
}

void UMovementState::Execute()
{
    ANeonPlayerController* PC = Cast<ANeonPlayerController>(AI->GetWorld()->GetFirstPlayerController());
    ANeonCharacter* player = PC->NeonCharacter;
    UWeaponComponent* weaponComp = UUtilsLibrary::GetRelativeComponent<UWeaponComponent>(AI);
    UAbilityComponent* abilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);
    UMotionComponent* motionComp = UUtilsLibrary::GetRelativeComponent<UMotionComponent>(AI);
    FString shoot = "Shoot";
    FString move = "MoveTo";
    UAbility* shootAbility = abilityComp->FindAbilityByName(shoot);
    UAbility* moveAbility = abilityComp->FindAbilityByName(move);
    float range = shootAbility->Data->Range;
    float dist = FVector::Dist(player->GetActorLocation(), AI->GetOwner()->GetActorLocation());
    if (dist > range)
    {
        TArray<FHitResult> hitResults = player->GetAbilityComponent()->GetActorsInRange(range);
        for (auto It = hitResults.CreateIterator(); It; It++)
        {
            AActor* actor = It->GetActor();
            if (actor->ActorHasTag(moveAbility->Data->ObjectTag)) {
                AGridBase* grid = Cast<AGridBase>(actor);
                if (grid != NULL && grid->GetLocationComponent()->GetStatus() == GridLocationStatus::Empty && grid->GetLocationComponent()->State == GridBaseState::Down) {
                    motionComp->MoveToGrid(actor);
                    break;
                }
            }
        }
        AI->EndTurn();
    }
}
