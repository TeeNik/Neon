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

public:

	FORCEINLINE TArray<UHealthInfoWidget*>& GetHeealthWidgets() { return HealthWidgets; }

	UHealthInfoWidget* AddHealthWidget(uint32& id);

protected:

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* HealthWidgetBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UHealthInfoWidget*> HealthWidgets;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> HealthWidgetBP;
};
