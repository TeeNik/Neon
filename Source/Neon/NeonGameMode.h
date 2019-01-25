#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NeonGameMode.generated.h"

class ULocationManager;
class UTurnManager;
class UAbilityManager;

UCLASS(minimalapi)
class ANeonGameMode : public AGameModeBase
{
GENERATED_BODY()

public:
	ANeonGameMode();

	virtual void BeginPlay() override;

	FORCEINLINE class ULocationManager* GetLocationManager() { return LocationManager; }
	FORCEINLINE class UTurnManager* GetTurnManager() { return TurnManager; }
	FORCEINLINE class UAbilityManager* GetAbilityManager() { return AbilityManager; }

protected:
	UPROPERTY(EditDefaultsOnly, Category="Managers")
	ULocationManager* LocationManager;

	UPROPERTY(EditDefaultsOnly, Category = "Managers")
	UTurnManager* TurnManager;

	UPROPERTY(EditDefaultsOnly, Category = "Managers")
	UAbilityManager* AbilityManager;
};



