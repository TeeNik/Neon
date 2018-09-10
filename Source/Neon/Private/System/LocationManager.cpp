#include "LocationManager.h"

ULocationManager::ULocationManager()
{

}

void ULocationManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters spawnParams;
	int size = 125;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j)
		{
			FVector location(-320-size*i,-500+size*j,200);
			GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0,0,0), spawnParams);
		}
	}

}