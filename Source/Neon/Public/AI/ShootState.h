#pragma once

#include "CoreMinimal.h"
#include "AI/AIState.h"
#include "ShootState.generated.h"

UCLASS()
class NEON_API UShootState : public UAIState
{
	GENERATED_BODY()

public:
	UShootState();
	virtual void Execute() override;
private:
	FName TargetTag;
};
