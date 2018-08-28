// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NeonCharacter.h"
#include "UI/ActionWidget.h"
#include "Action/Action.h"
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
	FString ActiveAction;

protected:
	uint32 bMoveToMouseCursor : 1;

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	void OnSetDestinationPressed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ActionWidgetTemplate;

public:
	void CreateFirstWidget();
	void CloseWidget();
	UPROPERTY(BlueprintReadOnly, Category="Neon")
	ANeonCharacter* NeonCharacter;
};


