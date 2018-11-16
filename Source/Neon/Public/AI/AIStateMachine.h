// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIStateMachine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UAIStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAIStateMachine();

protected:
	virtual void BeginPlay() override;

	
};
