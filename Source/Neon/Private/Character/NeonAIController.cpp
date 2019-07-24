#include "NeonAIController.h"
#include "System/UtilsLibrary.h"
#include "AI/AIStateMachine.h"
#include "AI/Bot/IdleState.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "NeonGameMode.h"
#include "MotionComponent.h"
#include "LocationManager.h"
#include "UtilsLibrary.h"

void ANeonAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
    Super::OnMoveCompleted(RequestID, Result);

	APawn* pawn = GetPawn();
    AActor* actor = Cast<AActor>(pawn);
    ACharacter* character = Cast<ACharacter>(actor);

    ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
    ULocationManager* LM = GM->GetLocationManager();
    UMotionComponent* MC = UUtilsLibrary::GetComponentByClass<UMotionComponent>(actor);
    if (LM->IsCover(MC->GetPosition())) {
        character->Crouch();
    }

	if (character->ActorHasTag("Enemy")) {
		UAIStateMachine* AI = UUtilsLibrary::GetComponentByClass<UAIStateMachine>(pawn);
		UAIState* state = NewObject<UIdleState>(this, UIdleState::StaticClass());
		AI->NextState(state);
	}
}

