#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AbilityManager.generated.h"

class UAbility;
struct FActionTableData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	UAbilityManager();

	UAbility* GetAbility(FString name);

	virtual void BeginDestroy();

protected:
	virtual void BeginPlay() override;
	TArray<UAbility*> abilities;
	TArray<FActionTableData*> abilityDatas;

	void InitAbility(UAbility* ability, FString name);

};
