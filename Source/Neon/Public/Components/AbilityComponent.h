// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UI/ActionWidget.h"
#include "Action/ActionTableData.h"
#include "AbilityComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
		UAbilityComponent();

	void SetIcons();
	UActionWidget* Widget;
	TMap<FName, FActionTableData*> Actions;
	FName* ActiveAction;
	
	void ShowAbilityRange(FName);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
