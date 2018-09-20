// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnergyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEnergyComponent();

protected:
	virtual void BeginPlay() override;
};
