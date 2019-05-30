#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NeonAIController.generated.h"

UCLASS()
class NEON_API ANeonAIController : public AAIController
{
	GENERATED_BODY()

public:

    void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
	
};
