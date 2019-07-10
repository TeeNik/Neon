#include "InfoWidgetManager.h"
#include "HealthComponent.h"

UInfoWidgetManager::UInfoWidgetManager()
{

}


void UInfoWidgetManager::BeginPlay()
{
	Super::BeginPlay();
}


void UInfoWidgetManager::RegisterEvent(UHealthComponent* comp)
{
	comp->OnDataUpdate.AddUFunction(this, "OnHealthChanged");
}

void UInfoWidgetManager::OnHealthChanged(UHealthComponent * comp)
{
}