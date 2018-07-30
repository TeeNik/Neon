// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.h"
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

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxComp;

public:	

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	FActionData GetActionList();
	virtual FActionData GetActionList_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void SetWidgetSettings(UActionWidget* widget);
	virtual void SetWidgetSettings_Implementation(UActionWidget* widget) override;

	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToMiddle();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveToTop();
	UFUNCTION(BlueprintCallable, Category = "Action")
	void MoveDown();

	void Move(float value);
	GridBaseState state;

};
