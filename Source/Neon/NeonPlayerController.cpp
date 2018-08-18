// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NeonPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "NeonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ANeonPlayerController::ANeonPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bEnableMouseOverEvents = true;
	ClickedActor = NULL;
}

void ANeonPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ANeonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ANeonPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("RightMouseButton", IE_Released, this, &ANeonPlayerController::CloseWidget);
}

void ANeonPlayerController::BeginPlay()
{

}

void ANeonPlayerController::OnSetDestinationPressed()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANeonCharacter::StaticClass(), FoundActors);
	FHitResult Hit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
	FVector MoveLocation;
	/*if (ANeonCharacter* MyPawn = Cast<ANeonCharacter>(FoundActors[0]))
	{
		if (MyPawn->GetCursorToWorld())
		{
			UNavigationSystem::SimpleMoveToActor(MyPawn->GetController(), Hit.GetActor());
		}
	}*/
	IAction* action = Cast<IAction>(Hit.GetActor());
	/*if (action) {
		action->Execute_GetActionList(Hit.GetActor());
	}*/
}

void ANeonPlayerController::CreateFirstWidget()
{
	if (ActionWidgetTemplate) {
		ActionWidget = CreateWidget<UActionWidget>(this, ActionWidgetTemplate);
		ActionWidget->AddToViewport();
	}
}

void ANeonPlayerController::CloseWidget()
{
	if (ClickedActor != NULL) {
		IAction::Execute_Deactivate(ClickedActor);
		ClickedActor = NULL;
		ActionWidget->SetVisibility(ESlateVisibility::Hidden);
	}

}
