#include "LocationManager.h"

ULocationManager::ULocationManager()
{

}

void ULocationManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters spawnParams;
	int size = 125;

	GridArray.SetNum(8);
	TestArray2 = new AGridBase*[100];
	int i = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j)
		{
			FVector location(-320-size*i,-500+size*j,200);
			auto gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0,0,0), spawnParams);
			gridBase->Row = i;
			gridBase->Column = j;
			GridArray[i].Array.Add(gridBase);
			TestArray.Add(gridBase);
			TestArray2[i++] = gridBase;
		}
	}
	GLog->Log("");
}

bool ULocationManager::IsTop(int i, int j)
{
	return GridArray[i].Array[j]->state == Top;
}

bool ULocationManager::IsUnderCover(AGridBase* gridBase)
{
	int i = gridBase->Row;
	int j = gridBase->Column;
	GLog->Log("");
	/*if (i > 0 && j > 0 && IsTop(i - 1, j - 1)) { return true; }
	if (j > 0 && IsTop(i,j-1)) { return true; }
	if (i + 1 < GridArray.Num() && j > 0 && IsTop(i+1,j-1)) { return true; }

	if (i > 0 && j + 1 < GridArray[i].Num() && IsTop(i - 1, j + 1)) { return true; }
	if (j + 1 < GridArray[i].Num() && IsTop(i, j + 1)) { return true; }
	if (i + 1 < GridArray.Num() && j + 1 < GridArray[i].Num() && IsTop(i + 1, j + 1)) { return true; }

	if (i > 0 && IsTop(i - 1, j)) { return true; }
	if (i + 1 < GridArray.Num() && IsTop(i + 1, j)) { return true; }*/

	return false;
}

