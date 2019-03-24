#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Action/Action.h"
#include "EnemyCharacter.generated.h"

class UMotionComponent;
class UMaterialInstance;
class UHealthComponent;
class UEnergyComponent;
class UAIStateMachine;
class UWeaponComponent;

UCLASS()
class NEON_API AEnemyCharacter : public ACharacter, public IAction
{
	GENERATED_BODY()

public:

	AEnemyCharacter();

	FORCEINLINE class UHealthComponent* GetHealthComponent() { return HealthComp; }

	UFUNCTION(BlueprintCallable, Category = "Action")
	virtual void OnBeginCursorOver(UPrimitiveComponent* TouchedComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Action")
	virtual void OnEndCursorOver(UPrimitiveComponent* TouchedComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Action")
	virtual void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed) override;

	UFUNCTION(BlueprintCallable, Category = "Action")
	virtual void Deactivate() override;

	UFUNCTION(BlueprintCallable, Category = "Action")
	virtual bool Highlight(FString& AbilityName) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UMotionComponent* MotionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UEnergyComponent* EnergyComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAIStateMachine* AI;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UWeaponComponent* WeaponComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;
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
	UFUNCTION()
	void OnStartTurn();
};
