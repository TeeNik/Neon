// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "Action/Action.h"
#include "EnemyCharacter.generated.h"

class UMotionComponent;
class UMaterialInstance;
class UHealthComponent;
class UEnergyComponent;

UCLASS()
class NEON_API AEnemyCharacter : public ACharacter//, public IAction
{
	GENERATED_BODY()

public:

	AEnemyCharacter();

	FORCEINLINE class UHealthComponent* GetHealthComponent() { return HealthComp; }

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
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
	virtual bool Highlight_Implementation(FString& AbilityName) override;*/

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UMotionComponent* MotionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UEnergyComponent* EnergyComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* SelectionCircle;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* DefaultMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* HighlightMaterial;
	
	UFUNCTION()
	void InitialMovement();

private:
	UFUNCTION()
	void HideCircle();
};
