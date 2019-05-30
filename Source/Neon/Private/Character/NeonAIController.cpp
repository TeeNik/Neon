#include "NeonAIController.h"

void ANeonAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
    Super::OnMoveCompleted(RequestID, Result);

    GLog->Log("MoveCompleted");
}

