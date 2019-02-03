#pragma once

#include "CoreMinimal.h"
#include "Action/Action.h"
#include "GameFramework/Actor.h"
#include "GridBase.generated.h"

class UMaterial;
class UActionWidget;
class UGridLocationComponent;
class UBoxComponent;

UCLASS()
class NEON_API AGridBase : public AActor, public IAction
{
	GENERATED_BODY()
	
public:	
	AGridBase();

	const FString TopAbility = TEXT("Top");
	const FString DownAbility = TEXT("Down");
	const FString MoveAbility = TEXT("MoveTo");

	FORCEINLINE class UGridLocationComponent* GetLocationComponent() { return GridLocationComp; }

	void Move(float value);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UGridLocationComponent* GridLocationComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* PlaneComp;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* DisableMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMaterial* ActiveMaterial;

public:	

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

	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToMiddle();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToTop();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveDown();

	int Row;
	int Column;
};
