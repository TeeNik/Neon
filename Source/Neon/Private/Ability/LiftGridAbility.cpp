#include "LiftGridAbility.h"
#include "GridBase.h"

void ULiftGridAbility::Execute(AActor* owner, AActor* target)
{
    AGridBase* grid = Cast<AGridBase>(target);
    grid->MoveToTop();
}
