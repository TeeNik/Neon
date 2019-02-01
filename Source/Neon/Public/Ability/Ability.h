#pragma once
#include "CoreMinimal.h"
#include "Ability.generated.h"

class AActor;
struct FActionTableData;

UCLASS()
class NEON_API UAbility : public UObject
{
	GENERATED_BODY()

public:
	UAbility();
	virtual ~UAbility();
	virtual void Execute(AActor*, AActor*);

	int32 Cooldown;
	FActionTableData* Data;
};

/*AGridBase* grid = Cast<AGridBase>(target);
	grid->GetLocationComponent()->SetStatus(GridLocationStatus::Player);
	UMotionComponent* motion = UUtilsLibrary::GetComponentByClass<UMotionComponent>(owner);
	motion->MoveToGrid(grid);*/
