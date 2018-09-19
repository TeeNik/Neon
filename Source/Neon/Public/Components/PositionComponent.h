// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldActors/GridBase.h"
#include "PositionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UPositionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPositionComponent();

	FORCEINLINE void SetPosition(AGridBase* pos) { Position = pos; }
	FORCEINLINE const AGridBase* GetPosition() { return Position; }

protected:
	virtual void BeginPlay() override;

private:
	AGridBase * Position;
};
