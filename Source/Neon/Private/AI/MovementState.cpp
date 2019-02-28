#include "MovementState.h"
#include "AIStateMachine.h"
#include "NeonPlayerController.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "UtilsLibrary.h"
#include "Components/AbilityComponent.h"
#include "NeonCharacter.h"
#include "Engine/World.h"

MovementState::MovementState(UAIStateMachine* ai) : AIState(AI)
{
	Name = "MovementState";
}

MovementState::~MovementState()
{
}

void MovementState::Execute()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(AI->GetWorld()->GetFirstPlayerController());
	ANeonCharacter* player = PC->NeonCharacter;
	UWeaponComponent* WeaponComp = UUtilsLibrary::GetRelativeComponent<UWeaponComponent>(AI);
	UAbilityComponent* AbilityComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(AI);

	float dist = FVector::Dist(player->GetActorLocation(), AI->GetOwner()->GetActorLocation());

}
