#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AbilityManager.generated.h"

class Ability;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	UAbilityManager();

	Ability* GetAbility();

	virtual void BeginDestroy();

protected:
	virtual void BeginPlay() override;

	TArray<Ability*> abilities;
};
