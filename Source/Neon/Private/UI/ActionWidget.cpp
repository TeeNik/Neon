// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionWidget.h"


void UActionWidget::ClearButtons()
{
	for (UButton* button : ButtonArray) {
		button->OnClicked.Clear();
	}
}

void UActionWidget::SetButtonImage(ButtonDirection direction, UTexture2D* texture)
{
	auto* button = ButtonArray[direction];
	button->WidgetStyle.Normal.SetResourceObject(texture);
	button->WidgetStyle.Hovered.SetResourceObject(texture);
	button->WidgetStyle.Pressed.SetResourceObject(texture);
}

void UActionWidget::InitButtons(TArray<FActionTableData*> actionDatas)
{
	if(actionDatas.Num() != ButtonArray.Num())
	{
		GLog->Log(("Init Buttons Error!!!"));
		return;
	}
	for(int i = 0; i < actionDatas.Num(); ++i)
	{
		GLog->Log(actionDatas[i]->Name);
		ButtonArray[i]->SetButtonData(actionDatas[i]);
	}	
}

void UActionWidget::InitEnergy(int32& num)
{
	auto world = GetWorld();
	for (int i = 0; i < num; ++i)
	{
		UEnergyImage* image = CreateWidget<UEnergyImage>(world, EnergyImageBP);
		EnergyBox->AddChildToHorizontalBox(image);
	}
}

