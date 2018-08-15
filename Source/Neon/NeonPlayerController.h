// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UI/ActionWidget.h"
#include "Action/Action.h"
#include "Action/ActionTableData.h"
#include "NeonPlayerController.generated.h"

UCLASS()
class ANeonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANeonPlayerController();

	UObject* ClickedActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	UActionWidget* ActionWidget;
	FName ActiveAction;

protected:
	uint32 bMoveToMouseCursor : 1;

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	void OnSetDestinationPressed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ActionWidgetTemplate;

public:
	void CloseWidget();

};


