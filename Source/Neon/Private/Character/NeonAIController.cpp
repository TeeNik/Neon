#include "NeonAIController.h"

void ANeonAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) {
    Super::OnMoveCompleted(RequestID, Result);

    GLog->Log("MoveCompleted");
}

