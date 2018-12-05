#include "MovementState.h"
#include "AIStateMachine.h"
#include "NeonPlayerController.h"
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
	float dist = FVector::Dist(PC->NeonCharacter->GetActorLocation(), AI->GetOwner()->GetActorLocation());

}
