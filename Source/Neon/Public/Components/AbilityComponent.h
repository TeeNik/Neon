// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UI/ActionWidget.h"
#include "AbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();

	TArray<FActionTableData*> Abilities;
	FActionTableData* ActiveAction;
	
	void ShowAbilityRange(FString&);
	void HideAbilityRange();

	virtual void BeginPlay() override;
	TArray<FHitResult> GetActorsInRange(FString& name);

protected:
	TArray<FHitResult> HighlighedObjects;
	FActionTableData* FindAbilityByName(FString);
	void InitAbilities();
};