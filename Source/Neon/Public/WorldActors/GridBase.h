#pragma once

#include "CoreMinimal.h"
#include "Action/Action.h"
#include "GameFramework/Actor.h"
#include "GridBase.generated.h"

enum GridBaseState {
	Down = 0,
	Middle = 50,
	Top = 100,
};

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
	GridBaseState State;

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

	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToMiddle();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToTop();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveDown();

	int Row;
	int Column;
};
