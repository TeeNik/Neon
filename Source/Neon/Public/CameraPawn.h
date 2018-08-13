// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "NeonPlayerController.h"
#include "CameraPawn.generated.h"

UCLASS()
class NEON_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	USceneComponent* RootScene;
	
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UCameraComponent* CameraComp;

	APlayerController* PC;
	FVector GetCameraPanDirection();
	void PanMoveCamera();

	UPROPERTY(EditDefaultsOnly, Category="CameraPawn")
	float Margin;

	UPROPERTY(EditDefaultsOnly, Category = "CameraPawn")
	float CamSpeed;

	int32 ScreenSizeX;
	int32 ScreenSizeY;
	ANeonPlayerController* NeonPC;

};
