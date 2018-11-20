// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MotionComponent.generated.h"

class AGridBase;

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UMotionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMotionComponent();

	FORCEINLINE AGridBase* GetPosition() { return Position; }
	void MoveToGrid(AGridBase* gridBase);

protected:
	virtual void BeginPlay() override;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position", meta = (AllowPrivateAccess = "true"))
	int32 Row;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Position", meta = (AllowPrivateAccess = "true"))
	int32 Column;

private:
	AGridBase * Position;

	UFUNCTION()
	void SetupInitialPosition();
};
