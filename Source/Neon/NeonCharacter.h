#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Action/Action.h"
#include "NeonCharacter.generated.h"

class UEnergyComponent;
class UMotionComponent;
class UHealthComponent;
class UWeaponComponent;
class UStaticMeshComponent;
class UAbilityComponent;
class UMaterialInstance;

UCLASS(Blueprintable)
class ANeonCharacter : public ACharacter, public IAction
{
	GENERATED_BODY()

public:
	ANeonCharacter();
	FORCEINLINE class UAbilityComponent* GetAbilityComponent() { return AbilityComp; }
	FORCEINLINE class UHealthComponent* GetHealthComponent() { return HealthComp; }
	FORCEINLINE class UWeaponComponent* GetWeaponComponent() { return WeaponComp; }
	FORCEINLINE class UMotionComponent* GetMotionComponent() { return MotionComp; }
	FORCEINLINE class UEnergyComponent* GetEnergyComponent() { return EnergyComp; }

	void BeginPlay() override;

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

	UFUNCTION()
	void OnPlayerActionCall(AActor* target);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* SelectionCircle;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* DefaultMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* HighlightMaterial;

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

