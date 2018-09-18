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
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j)
		{
			FVector location(-320-size*i,-500+size*j,200);
			auto gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0,0,0), spawnParams);
			gridBase->Row = i;
			gridBase->Column = j;
			GridArray[i].Array.Add(gridBase);
		}
	}
}

bool ULocationManager::IsTop(int i, int j)
{
	return GridArray[i].Array[j]->state == Top;
}

Direction ULocationManager::GetCoverInfo(AGridBase* gridBase)
{
	Direction dir;
	int i = gridBase->Row;
	int j = gridBase->Column;
	if (i > 0 && j > 0 && IsTop(i - 1, j - 1)) { dir.Right = true; dir.Up = true; GLog->Log("R U"); }
	if (j > 0 && IsTop(i, j - 1)) { dir.Right = true; GLog->Log("R"); }
	if (i + 1 < GridArray.Num() && j > 0 && IsTop(i + 1, j - 1)) { dir.Right = true; dir.Down = true; GLog->Log("R D"); }

	if (i > 0 && j + 1 < GridArray[i].Array.Num() && IsTop(i - 1, j + 1)) { dir.Left = true; dir.Up = true; GLog->Log("L U"); }
	if (j + 1 < GridArray[i].Array.Num() && IsTop(i, j + 1)) { dir.Left = true; GLog->Log("L"); }
	if (i + 1 < GridArray.Num() && j + 1 < GridArray[i].Array.Num() && IsTop(i + 1, j + 1)) { dir.Left = true; dir.Down = true; GLog->Log("L D"); }

	if (i > 0 && IsTop(i - 1, j)) { dir.Up = true; GLog->Log("U"); }
	if (i + 1 < GridArray.Num() && IsTop(i + 1, j)) { dir.Down = true; GLog->Log("D"); }

	return dir;
}

