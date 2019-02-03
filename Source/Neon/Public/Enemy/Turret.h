#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Action/Action.h"
#include "Turret.generated.h"

enum class TurretStatus {
	DisableTurret,
	PlayerTurret,
	EnemyTurret
};

class UStaticMeshComponent;
class UHealthComponent;
class UEnergyComponent;
class UMotionComponent;
class UWeaponComponent;
class UMaterial;
class UMaterialInstance;

UCLASS()
class NEON_API ATurret : public APawn, public IAction
{
	GENERATED_BODY()

public:
	ATurret();

	const FString ActivateAbility = TEXT("ActivateAbility");
	
	TurretStatus Status;

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
	class UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UHealthComponent* HealthComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UWeaponComponent* WeaponComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UMotionComponent* MotionComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UEnergyComponent* EnergyComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* DisableMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* PlayerMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* EnemyMaterial;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* SelectionCircle;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* DefaultMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* HighlightMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* GreenCircle;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* RedCircle;

private:
	void ActivateByPlayer();
	void ActivateByEnemy();
	UFUNCTION()
	void ExecuteTurn();
	void Shoot();
	
};
