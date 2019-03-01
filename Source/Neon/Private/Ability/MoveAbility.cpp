#include "MoveAbility.h"
#include "Components/GridLocationComponent.h"
#include "Components/MotionComponent.h"
#include "GameFramework/Actor.h"
#include "System/UtilsLibrary.h"

void UMoveAbility::Execute(AActor * owner, AActor * target)
{
	UGridLocationComponent* grid = UUtilsLibrary::GetComponentByClass<UGridLocationComponent>(target);
	grid->SetStatus(GridLocationStatus::Player);
	UMotionComponent* motion = UUtilsLibrary::GetComponentByClass<UMotionComponent>(owner);
	motion->MoveToGrid(target);
	Super::Execute(owner, target);
}
