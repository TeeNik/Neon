// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"
#include "Public/CameraPawn.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootScene);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-50, 0, 0));

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);

	Margin = 15;
	CamSpeed = 10;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	PC = Cast<APlayerController>(GetController());
	PC->GetViewportSize(ScreenSizeX, ScreenSizeY);
	NeonPC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PanMoveCamera();
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FVector ACameraPawn::GetCameraPanDirection()
{
	float MousePosX;
	float MousePosY;
	float CamDirectionX = 0;
	float CamDirectionY = 0;

	PC->GetMousePosition(MousePosX, MousePosY);

	if(MousePosX <= Margin)
	{
		CamDirectionY = -1;
	} 
	else if(MousePosX >= ScreenSizeX-Margin)
	{
		CamDirectionY = 1;
	}

	if(MousePosY <= Margin)
	{
		CamDirectionX = 1;
	}
	else if (MousePosY >= ScreenSizeY - Margin)
	{
		CamDirectionX = -1;
	}

	return FVector(CamDirectionX, CamDirectionY, 0);
}

void ACameraPawn::PanMoveCamera()
{
	const FVector dir = GetCameraPanDirection();
	if (dir == FVector::ZeroVector || NeonPC && NeonPC->ClickedActor != NULL) return;
	//AddActorWorldOffset(dir * CamSpeed);
}

