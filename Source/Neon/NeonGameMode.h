// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "System/LocationManager.h"
#include "System/TurnManager.h"
#include "NeonGameMode.generated.h"

UCLASS(minimalapi)
class ANeonGameMode : public AGameModeBase
{
GENERATED_BODY()

public:
	ANeonGameMode();

	virtual void BeginPlay() override;

	FORCEINLINE class ULocationManager* GetLocationManager() { return LocationManager; }
	FORCEINLINE class UTurnManager* GetTurnManager() { return TurnManager; }

protected:
	UPROPERTY(EditDefaultsOnly, Category="Managers")
	ULocationManager* LocationManager;

	UPROPERTY(EditDefaultsOnly, Category = "Managers")
	UTurnManager* TurnManager;
};



