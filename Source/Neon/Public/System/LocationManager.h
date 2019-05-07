#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LocationManager.generated.h"

DECLARE_MULTICAST_DELEGATE(OnSceneLoadedDelegate)

class AGridBase;
class UWeaponComponent;
struct Direction;

USTRUCT()
struct FGridBaseArray
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<AGridBase*> Array;
};

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API ULocationManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	ULocationManager();
	UPROPERTY()
	TArray<FGridBaseArray> GridArray;

	UPROPERTY(EditDefaultsOnly, Category = "LocationManager")
	TSubclassOf<AGridBase> GridBaseClass;

	Direction GetCoverInfo(const AGridBase* gridBase);
	OnSceneLoadedDelegate OnSceneLoaded;

	UFUNCTION()
	void SceneLoaded();

protected:
	virtual void BeginPlay() override;

private:

    enum MapElements {
        Wall = 1,
        Cover,
        Floor,
        Enemy,
        Turret,
    };

	bool IsTop(int i, int j);

    void GenerateMap();

    void CreateGridBase(FVector& location);
    void CreateWall(int& i, int& j);
    void CreateCover(int& i, int& j);
    void CreateFloor(int& i, int& j);
    void CreateTurret(int& i, int& j);
    void CreateEnemy(int& i, int& j);

};
