// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridLocationComponent.generated.h"

enum class GridLocationStatus
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

	FORCEINLINE void SetStatus(GridLocationStatus newStatus) { status = newStatus; }
	FORCEINLINE const GridLocationStatus& GetStatus() const { return status; };
	
protected:
	virtual void BeginPlay() override;

private:
	GridLocationStatus status;
};
