#include "InfoWidgetManager.h"
#include "HealthComponent.h"
#include "ActionWidget.h"
#include "NeonPlayerController.h"
#include "HealthInfoWidget.h"

UInfoWidgetManager::UInfoWidgetManager()
{

}


void UInfoWidgetManager::BeginPlay()
{
	Super::BeginPlay();
    ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
    if (IsValid(PC)) {
        ActionWidgetRef = PC->ActionWidget;
    }
}


void UInfoWidgetManager::RegisterEvent(UHealthComponent* comp)
{
    comp->OnDataUpdate.AddUFunction(this, "OnHealthChanged");
    ActionWidgetRef->AddInfoWidget();
}

void UInfoWidgetManager::OnHealthChanged(UHealthComponent * comp)
{
}