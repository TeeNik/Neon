// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Action/Action.h"
#include "Components/HealthComponent.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class NEON_API AEnemyCharacter : public ACharacter, public IAction
{
	GENERATED_BODY()

	FORCEINLINE class UHealthComponent* GetHealthComponent() { return HealthComp; }

public:
	AEnemyCharacter();

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
	void Highlight();
	virtual void Highlight_Implementation() override;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
};