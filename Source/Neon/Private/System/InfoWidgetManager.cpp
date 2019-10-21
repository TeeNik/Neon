#include "InfoWidgetManager.h"
#include "HealthComponent.h"
#include "LevelInfoWidget.h"
#include "NeonPlayerController.h"
#include "HealthInfoWidget.h"
#include "Engine/World.h"

UInfoWidgetManager::UInfoWidgetManager()
{

}

void UInfoWidgetManager::BeginPlay()
{
	Super::BeginPlay();
    if (LevelInfoClass) {
        LevelWidget = CreateWidget<ULevelInfoWidget>(GetOwner()->GetWorld(), LevelInfoClass);
        LevelWidget->AddToViewport();
    }
}

void UInfoWidgetManager::RegisterEvent(UHealthComponent* comp)
{
    comp->OnDataUpdate.AddUFunction(this, "OnHealthChanged");
    uint32 id = comp->GetOwner()->GetUniqueID();
	//LevelWidget->AddInfoWidget(id);
}

void UInfoWidgetManager::OnHealthChanged(UHealthComponent * comp)
{
    uint32 id = comp->GetOwner()->GetUniqueID();
    /*TArray<UHealthInfoWidget*> widgets = ActionWidgetRef->GetInfoWidgets();
    for (int i = 0; i < widgets.Num(); ++i)
    {
        if (widgets[i]->GetID() == id) {

        }
    }*/
}