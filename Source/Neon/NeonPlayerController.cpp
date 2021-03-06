#include "NeonPlayerController.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "NeonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AbilityComponent.h"
#include "UI/ActionWidget.h"
#include "NeonCharacter.h"
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

	InputComponent->BindAction("RightMouseButton", IE_Released, this, &ANeonPlayerController::CloseWidget);
}

void ANeonPlayerController::BeginPlay()
{

}

void ANeonPlayerController::CreateFirstWidget()
{
	if (ActionWidgetTemplate) {
		ActionWidget = CreateWidget<UActionWidget>(this, ActionWidgetTemplate);
		ActionWidget->AddToViewport();
		ActionWidget->InitToolTip();
	}
}

void ANeonPlayerController::CloseWidget()
{
	NeonCharacter->GetAbilityComponent()->HideAbilityRange();
}
