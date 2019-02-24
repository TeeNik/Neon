#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionButtonWidget.generated.h"

class UActionButton;
class UTextBlock;
class UImage;
struct FActionTableData;

UCLASS()
class NEON_API UActionButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	UActionButton* ActionButton;
	
	UPROPERTY(meta = (BindWidget))
	UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CooldownText;

	UPROPERTY(meta = (BindWidget))
	UImage* CooldownDark;

	FActionTableData* Data;

	void SetWidgetData(FActionTableData* data);

};
