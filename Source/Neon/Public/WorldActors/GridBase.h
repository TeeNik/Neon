// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "UI/ActionWidget.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GridBase.generated.h"

enum GridBaseState {
	Down = 0,
	Middle = 50,
	Top = 100,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestDel, int, num);

UCLASS()
class NEON_API AGridBase : public AActor, public IAction
{
	GENERATED_BODY()
	
public:	
	AGridBase();

	void OnSuccessClick();
	void Move(float value);
	GridBaseState state;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxComp;

public:	

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	FActionData GetActionList();
	virtual FActionData GetActionList_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void SetWidgetSettings(UActionWidget* widget);
	virtual void SetWidgetSettings_Implementation(UActionWidget* widget) override;*/

	void SetWidgetSettings(UActionWidget* widget);

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

	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToMiddle();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToTop();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveDown();

	void Highlight();

};
