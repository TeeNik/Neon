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
    uint32 id = comp->GetOwner()->GetUniqueID();
    ActionWidgetRef->AddInfoWidget(id);
}

void UInfoWidgetManager::OnHealthChanged(UHealthComponent * comp)
{
    uint32 id = comp->GetOwner()->GetUniqueID();
    TArray<UHealthInfoWidget*> widgets = ActionWidgetRef->GetInfoWidgets();
    for (int i = 0; i < widgets.Num(); ++i)
    {
        if (widgets[i]->GetID() == id) {

        }
    }
}