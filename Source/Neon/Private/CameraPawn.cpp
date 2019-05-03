#include "CameraPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "NeonPlayerController.h"
#include "Engine/World.h"

ACameraPawn::ACameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootScene);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-50, 0, 0));

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);

	Margin = 2;
	CamSpeed = 10;
}

void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	PC = Cast<APlayerController>(GetController());
	PC->GetViewportSize(ScreenSizeX, ScreenSizeY);
	NeonPC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
}

void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PanMoveCamera();
}

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

    FVector location = GetActorLocation();
    if (dir.Y < 0 && location.Y < BoundY.X || dir.Y > 0 && location.Y > BoundY.Y || dir.X > 0 && location.X > BoundX.X || dir.X < 0 && location.X < BoundX.Y) return;

	AddActorWorldOffset(dir * CamSpeed);
}

