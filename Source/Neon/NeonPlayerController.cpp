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
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		float const Distance = FVector::Dist(Hit.ImpactPoint, NeonCharacter->GetActorLocation());
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(NeonCharacter->GetController(), Hit.ImpactPoint);
		}
	}
	
	
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
	NeonCharacter->GetAbilityConponent()->HideAbilityRange();
	/*if (ClickedActor != NULL) {
		IAction::Execute_Deactivate(ClickedActor);
		ClickedActor = NULL;
		ActionWidget->SetVisibility(ESlateVisibility::Hidden);
	}*/

}
