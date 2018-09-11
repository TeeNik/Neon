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
		TArray<AGridBase*> array;
		GridArray.Add(array);
		for (int j = 0; j < 10; ++j)
		{
			FVector location(-320-size*i,-500+size*j,200);
			auto gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0,0,0), spawnParams);
			gridBase->Row = i;
			gridBase->Column = j;
			GridArray[i].Add(gridBase);
		}
	}

}

bool ULocationManager::IsTop(int i, int j)
{
	return GridArray[i][j]->state == Top;
}

void ULocationManager::IsUnderCover(AGridBase* gridBase)
{
	int i = gridBase->Row;
	int j = gridBase->Column;

	if (i > 0 & j > 0 & IsTop(i-1, j)) {}
	if (i > 0 & IsTop(i-1,j)) {}
	if (i > 0 & j < GridArray[i].Num() & IsTop(i-1,j+1)) {}

}

