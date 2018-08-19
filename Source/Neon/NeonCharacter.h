// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/AbilityComponent.h"
#include "Components/HealthComponent.h"
#include "NeonCharacter.generated.h"

UCLASS(Blueprintable)
class ANeonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANeonCharacter();
	FORCEINLINE class UAbilityComponent* GetAbilityConponent() { return AbilityComp; }

	void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void GetMovementArea();

};

