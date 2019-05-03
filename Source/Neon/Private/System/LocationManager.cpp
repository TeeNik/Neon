#include "LocationManager.h"
#include "InputCoreTypes.h"
#include "WorldActors/GridBase.h"
#include "Components/WeaponComponent.h"
#include "Components/GridLocationComponent.h"
#include "Engine/Public/TimerManager.h"
#include "Engine/World.h"
#include "JsonUtilities.h"

ULocationManager::ULocationManager()
{

}

void ULocationManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters spawnParams;
	int size = 125;

	/*GridArray.SetNum(8);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 10; ++j)
		{
			FVector location(-320-size*i,-440+size*j,200);
			auto gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0,0,0), spawnParams);
			gridBase->Row = i;
			gridBase->Column = j;
			GridArray[i].Array.Add(gridBase);
		}
	}*/

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

                if (block == 1) {
                    FVector location(-320 - size * i, -440 + size * j, 350);
                    auto gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0, 0, 0), spawnParams);
                    gridBase->Row = i;
                    gridBase->Column = j;
                    GridArray[i].Array.Add(gridBase);
                }
                else {
                    FVector location(-320 - size * i, -440 + size * j, 200);
                    auto gridBase = GetWorld()->SpawnActor<AGridBase>(GridBaseClass, location, FRotator(0, 0, 0), spawnParams);
                    gridBase->Row = i;
                    gridBase->Column = j;
                    GridArray[i].Array.Add(gridBase);
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

