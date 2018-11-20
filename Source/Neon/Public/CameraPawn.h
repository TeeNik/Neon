#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

class ANeonPlayerController;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class NEON_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	ACameraPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

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
