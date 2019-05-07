#include "LocationManager.h"
#include "InputCoreTypes.h"
#include "WorldActors/GridBase.h"
#include "Enemy/Turret.h"
#include "Enemy/EnemyCharacter.h"
#include "WorldActors/GridBase.h"
#include "Components/WeaponComponent.h"
#include "Components/GridLocationComponent.h"
#include "Components/MotionComponent.h"
#include "Engine/Public/TimerManager.h"
#include "Engine/World.h"
#include "UtilsLibrary.h"
#include "JsonUtilities.h"

ULocationManager::ULocationManager()
{

}

void ULocationManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters spawnParams;
	FTimerHandle timer;
	GetWorld()->GetTimerManager().SetTimer(timer, this, &ULocationManager::SceneLoaded, 1, false);

    GenerateMap();
}

bool ULocationManager::IsTop(int i, int j)
{
	return GridArray[i].Array[j]->GetLocationComponent()->State == Top;
}

void ULocationManager::GenerateMap()
{
    const FString JsonFilePath = FPaths::ProjectContentDir() + "TopDownCPP/Data/map.json";
    FString JsonString; //Json converted to FString

    GLog->Log("Path: " + JsonFilePath);

    FFileHelper::LoadFileToString(JsonString, *JsonFilePath);

    //Displaying the json in a string format inside the output log
    GLog->Log("Json String:");
    GLog->Log(JsonString);

    //Create a json object to store the information from the json string
    //The json reader is used to deserialize the json object later on
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);

    if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
    {
        //The person "object" that is retrieved from the given json file
        TSharedPtr<FJsonObject> MapObject = JsonObject->GetObjectField("Map");
        int width = MapObject->GetIntegerField("width");
        int height = MapObject->GetIntegerField("height");
        
        GLog->Log("width:" + FString::FromInt(MapObject->GetIntegerField("width")));
        GLog->Log("height:" + FString::FromInt(MapObject->GetIntegerField("height")));

        //Retrieving an array property and printing each field
        TArray<TSharedPtr<FJsonValue>> data = MapObject->GetArrayField("data");
        GLog->Log("printing family names...");

        int k = 0;
        int size = 125;
        FActorSpawnParameters spawnParams;
        GridArray.SetNum(height);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j)
            {
                int block = data[k]->AsNumber();

                switch (block)
                {
                case Wall:
                    CreateWall(i, j);
                    break;
                case Cover:
                    CreateCover(i, j);
                    break;
                case Floor:
                    CreateFloor(i, j);
                    break;
                case Enemy:
                    CreateEnemy(i, j);
                    break;
                case Turret:
                    CreateTurret(i, j);
                    break;
                default:
                    break;
                }

                ++k;
            }
        }

        for (int32 index = 0; index < data.Num(); index++)
        {

            GLog->Log("name:" + data[index]->AsString());
        }
    }
    else
    {
        GLog->Log("couldn't deserialize");
    }
}

void ULocationManager::CreateGridBase(FVector& location, int& i, int& j)
{
    FActorSpawnParameters spawnParams;
    AGridBase* gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0, 0, 0), spawnParams);
    gridBase->Row = i;
    gridBase->Column = j;
    GridArray[i].Array.Add(gridBase);
}

void ULocationManager::CreateWall(int & i, int & j)
{
    FVector location(-320 - BLOCK_SIZE * i, -440 + BLOCK_SIZE * j, 350);
    CreateGridBase(location, i, j);
}

void ULocationManager::CreateCover(int& i, int& j)
{
    FVector location(-320 - BLOCK_SIZE * i, -440 + BLOCK_SIZE * j, 300);
    CreateGridBase(location, i, j);
}

void ULocationManager::CreateFloor(int& i, int& j)
{
    FVector location(-320 - BLOCK_SIZE * i, -440 + BLOCK_SIZE * j, 200);
    CreateGridBase(location, i, j);
}

void ULocationManager::CreateTurret(int& i, int& j)
{
    CreateFloor(i, j);
    FActorSpawnParameters spawnParams;
    ATurret* turret = GetWorld()->SpawnActor<ATurret>(TurretClass);
    UMotionComponent* motion = UUtilsLibrary::GetComponentByClass<UMotionComponent>(turret);
    motion->SetupInitialPosition(GridArray[i].Array[j]);
}

void ULocationManager::CreateEnemy(int& i, int& j)
{
    CreateFloor(i, j);
    FActorSpawnParameters spawnParams;
    AEnemyCharacter* enemy = GetWorld()->SpawnActor<AEnemyCharacter>(EnemyClass);
    UMotionComponent* motion = UUtilsLibrary::GetComponentByClass<UMotionComponent>(enemy);
    motion->SetupInitialPosition(GridArray[i].Array[j]);
}

Direction ULocationManager::GetCoverInfo(const AGridBase* gridBase)
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

void ULocationManager::SceneLoaded()
{
	OnSceneLoaded.Broadcast();
}

