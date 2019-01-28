#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AbilityManager.generated.h"

class Ability;
struct FActionTableData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	UAbilityManager();

	Ability* GetAbility(FString name);

	virtual void BeginDestroy();

protected:
	virtual void BeginPlay() override;
	TArray<Ability*> abilities;
	TArray<FActionTableData*> abilityDatas;

	void InitAbility(Ability* ability, FString name);

};
