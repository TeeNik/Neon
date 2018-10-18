// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/AbilityComponent.h"
#include "Components/HealthComponent.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "Components/EnergyComponent.h"
#include "NeonCharacter.generated.h"

UCLASS(Blueprintable)
class ANeonCharacter : public ACharacter, public IAction
{
	GENERATED_BODY()

public:
	ANeonCharacter();
	FORCEINLINE class UAbilityComponent* GetAbilityConponent() { return AbilityComp; }
	FORCEINLINE class UHealthComponent* GetHealthComponent() { return HealthComp; }
	FORCEINLINE class UWeaponComponent* GetWeaponComponent() { return WeaponComp; }
	FORCEINLINE class UMotionComponent* GetMotionComponent() { return MotionComp; }
	FORCEINLINE class UEnergyComponent* GetEnergyComponent() { return EnergyComp; }

	void BeginPlay() override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void OnBeginCursorOver(UPrimitiveComponent* TouchedComponent);
	virtual void OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void OnEndCursorOver(UPrimitiveComponent* TouchedComponent);
	virtual void OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);
	virtual void OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void Deactivate();
	virtual void Deactivate_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	bool Highlight(FString& AbilityName);
	virtual bool Highlight_Implementation(FString& AbilityName) override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UWeaponComponent* WeaponComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UMotionComponent* MotionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UEnergyComponent* EnergyComp;

	UFUNCTION()
	void OnSpendEnergy(int current, int value);
};

