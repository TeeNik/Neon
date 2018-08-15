// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UI/ActionWidget.h"
#include "AbilityComponent.generated.h"


class Ability {
	FString Name;
	float Range;
	TSubclassOf<class Aactor> TargetClass;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
		UAbilityComponent();

	void SetIcons();
	UActionWidget* widget;
	
	void ShowAbilityRange();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TArray<Ability> abilities;
	
};
