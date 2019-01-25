#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

struct FActionTableData;
class Ability;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();

	TArray<Ability*> Abilities;
	Ability* ActiveAction;
	
	void ShowAbilityRange(FString&);
	void HideAbilityRange();

	virtual void BeginPlay() override;
	TArray<FHitResult> GetActorsInRange(FString& name);

protected:
	TArray<FHitResult> HighlighedObjects;
	Ability* FindAbilityByName(FString);
	void InitAbilities();
};