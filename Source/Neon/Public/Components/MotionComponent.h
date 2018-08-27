// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldActors/GridBase.h"
#include "MotionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UMotionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMotionComponent();

	void MoveToGrid(AGridBase* gridBase);

protected:
	virtual void BeginPlay() override;	
	
};
