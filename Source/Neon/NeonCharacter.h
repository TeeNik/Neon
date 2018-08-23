// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/AbilityComponent.h"
#include "Components/HealthComponent.h"
#include "Components/WeaponComponent.h"
#include "NeonCharacter.generated.h"

UCLASS(Blueprintable)
class ANeonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANeonCharacter();
	FORCEINLINE class UAbilityComponent* GetAbilityConponent() { return AbilityComp; }
	FORCEINLINE class UHealthComponent* GetHealthComponent() { return HealthComp; }
	FORCEINLINE class UWeaponComponent* GetWeaponComponent() { return WeaponComp; }

	void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UWeaponComponent* WeaponComp;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void GetMovementArea();

};

