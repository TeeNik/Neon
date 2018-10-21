// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/HealthComponent.h"
#include "Components/WeaponComponent.h"
#include "Components/MotionComponent.h"
#include "Components/EnergyComponent.h"
#include "Turret.generated.h"

enum class TurretStatus {
	DisableTurret,
	PlayerTurret,
	EnemyTurret
};

UCLASS()
class NEON_API ATurret : public APawn, public IAction
{
	GENERATED_BODY()

public:
	ATurret();

	const FString ActivateAbility = TEXT("ActivateTurret");
	
	TurretStatus Status;

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

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UWeaponComponent* WeaponComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UMotionComponent* MotionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UEnergyComponent* EnergyComp;


	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* DisableMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* PlayerMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* EnemyMaterial;

private:
	void ActivateByPlayer();
	void ActivateByEnemy();
	
};
