#include "ResourceManagerLibrary.h"
#include "System/ResourceManager.h"
#include "Engine.h"

UResourceManagerLibrary::UResourceManagerLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

UResourceManager* UResourceManagerLibrary::GetData() {
	UResourceManager* DataInstance = Cast<UResourceManager>(GEngine->GameSingleton);
	if (!DataInstance) return NULL;
	if (!DataInstance->IsValidLowLevel()) return NULL;
	return DataInstance;
}
