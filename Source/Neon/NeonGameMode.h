// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WorldActors/GridBase.h"
#include "NeonGameMode.generated.h"

UCLASS(minimalapi)
class ANeonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANeonGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category="Config")
	TSubclassOf<AGridBase> GridBaseClass;
};



