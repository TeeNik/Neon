#include "NeonAIController.h"
#include "System/UtilsLibrary.h"
#include "AI/AIStateMachine.h"
#include "AI/IdleState.h"
#include "GameFramework/Character.h"

void ANeonAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
    Super::OnMoveCompleted(RequestID, Result);

    GLog->Log("MoveCompleted");

	APawn* pawn = GetPawn();
    AActor* actor = Cast<AActor>(pawn);
    ACharacter* character = Cast<ACharacter>(actor);
    character->Crouch();
	if (character->ActorHasTag("Enemy")) {
		UAIStateMachine* AI = UUtilsLibrary::GetComponentByClass<UAIStateMachine>(pawn);
		UAIState* state = NewObject<UIdleState>(this, UIdleState::StaticClass());
		AI->NextState(state);
	}
}

