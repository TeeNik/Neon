#include "CoverInfoAbility.h"
#include "GridBase.h"
#include "NeonGameMode.h"
#include "LocationManager.h"
#include "Engine/World.h"
#include "WeaponComponent.h"

void UCoverInfoAbility::Execute(AActor* owner, AActor* target)
{
    AGridBase* grid = Cast<AGridBase>(target);
    ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
    ULocationManager* LM = GM->GetLocationManager();
    LM->GetCoverInfo(grid);
    Super::Execute(owner, target);
}
