#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

struct FActionTableData;
class UAbility;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();

	UPROPERTY()
	TArray<UAbility*> Abilities;
	UPROPERTY()
	UAbility* ActiveAction;
	
	void ShowAbilityRange(FString&);
	void HideAbilityRange();

	virtual void BeginPlay() override;
	TArray<FHitResult> GetActorsInRange(float radius);
	void SetActiveAction(FString&);
	UAbility* FindAbilityByName(FString&);

protected:
	TArray<FHitResult> HighlighedObjects;
	void InitAbilities();
};