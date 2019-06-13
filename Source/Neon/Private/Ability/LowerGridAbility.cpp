#include "LowerGridAbility.h"
#include "GridBase.h"

void ULowerGridAbility::Execute(AActor* owner, AActor* target)
{
    AGridBase* grid = Cast<AGridBase>(target);
    grid->MoveDown();
    Super::Execute(owner, target);
}