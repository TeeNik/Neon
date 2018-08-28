// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridLocationComponent.generated.h"

enum GridLocationStatus
{
	Empty,
	Player,
	Enemy
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UGridLocationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGridLocationComponent();

	void SetStatus(GridLocationStatus);

protected:
	virtual void BeginPlay() override;

private:
	GridLocationStatus status;
};
