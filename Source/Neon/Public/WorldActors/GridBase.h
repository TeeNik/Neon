// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GridBase.generated.h"

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
	bool GetActionList();
	virtual bool GetActionList_Implementation() override;
	
};
