#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Action/Action.h"
#include "CoreEnemy.generated.h"

class UMaterialInstance;

UCLASS()
class NEON_API ACoreEnemy : public APawn, public IAction
{
	GENERATED_BODY()

public:
	ACoreEnemy();

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
	class UEnergyComponent* EnergyComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAIStateMachine* AI;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* AbilityComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* SelectionCircle;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* DefaultMaterial;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterialInstance* HighlightMaterial;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NeonComponent", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* Capsule;


private:
	UFUNCTION()
	void HideCircle();
	UFUNCTION()
	void OnStartTurn();

};
