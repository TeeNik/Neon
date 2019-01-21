// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionWidget.generated.h"

typedef TMulticastDelegate<void, int32, int32> OnSpendEnergyDelegate;
typedef TMulticastDelegate<void> OnStartTurnDelegate;
typedef TMulticastDelegate<void> OnEndTurnDelegate;

enum class ButtonDirection {
	Left,
	Upper,
	Right,
	Lower
};

class UActionButtonWidget;
class UButton;
struct FActionTableData;
class UEnergyImage;
class UActionTooltip;
class UHorizontalBox;

UCLASS()
class NEON_API UActionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void ClearButtons();
	void InitButtons(TArray<FActionTableData*> actionDatas);
	void InitEnergy(int32& num, OnSpendEnergyDelegate&, OnStartTurnDelegate& , OnEndTurnDelegate&);
	void InitToolTip();

	FORCEINLINE UActionTooltip* GetActionTooltip() { return ActionTooltip; }

	void ShowEnergyCost(const int32& current, const int32& cost);
	void HideEnergyCost(const int32& current);

protected:
	UPROPERTY(BlueprintReadWrite)
	UActionTooltip * ActionTooltip;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UActionButtonWidget*> ButtonArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	TArray<UEnergyImage*> EnergyImages;

	UPROPERTY(BlueprintReadWrite, BlueprintReadWrite, Category = "UI")
	UHorizontalBox* EnergyBox;

	UPROPERTY(BlueprintReadWrite, BlueprintReadWrite, Category = "UI")
	UHorizontalBox* ActionBox;

	UPROPERTY(BlueprintReadWrite, BlueprintReadWrite, Category = "UI")
	UButton* SkipButton;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEnergyImage> EnergyImageBP;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UActionButtonWidget> AbilityButton;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UActionTooltip> ActionTooltipBP;

private:
	UFUNCTION()
	void DisableEnergyImages(int current, int value);
	UFUNCTION()
	void EnableEnergyImages(int value);
	UFUNCTION()
	void UpdateAbilityPanel(int current, int value);
	UFUNCTION()
	void SkipTurn();

};
