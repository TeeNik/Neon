#include "MoveAbility.h"
#include "WorldActors/GridBase.h"
#include "System/UtilsLibrary.h"
#include "Components/GridLocationComponent.h"
#include "Components/MotionComponent.h"

MoveAbility::MoveAbility()
{
}

MoveAbility::~MoveAbility()
{
}

void MoveAbility::Execute(AActor* owner, AActor* target)
{
	AGridBase* grid = Cast<AGridBase>(target);
	grid->GetLocationComponent()->SetStatus(GridLocationStatus::Player);
	UMotionComponent* motion = UUtilsLibrary::GetComponentByClass<UMotionComponent>(owner);
	motion->MoveToGrid(grid);
}