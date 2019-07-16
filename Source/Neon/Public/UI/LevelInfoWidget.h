#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelInfoWidget.generated.h"

class UHorizontalBox;
class UHealthInfoWidget;

UCLASS()
class NEON_API ULevelInfoWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* InfoWidgetBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UHealthInfoWidget*> HealthWidgets;
	
};
