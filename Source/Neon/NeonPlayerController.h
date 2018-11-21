#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NeonPlayerController.generated.h"

class UActionWidget;
class ANeonCharacter;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ActionWidgetTemplate;

public:
	void CreateFirstWidget();
	void CloseWidget();
	UPROPERTY(BlueprintReadOnly, Category="Neon")
	ANeonCharacter* NeonCharacter;
};


