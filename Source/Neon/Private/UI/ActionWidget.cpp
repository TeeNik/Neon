// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionWidget.h"

/*bool UActionWidget::Initialize()
{
	bool inited = Super::Initialize();

	/*ButtonArray.Add(LowerButton);
	ButtonArray.Add(UpperButton);
	ButtonArray.Add(LeftButton);
	ButtonArray.Add(RightButton);

	return inited;
}*/

void UActionWidget::ClearButtons()
{
	for (UButton* button : ButtonArray) {
		button->OnClicked.Clear();
		button->SetVisibility(ESlateVisibility::Hidden);
	}
	/*LeftButton->OnClicked.Clear();
	UpperButton->OnClicked.Clear();
	LowerButton->OnClicked.Clear();
	RightButton->OnClicked.Clear();
	LeftButton->SetVisibility(ESlateVisibility::Visible);
	UpperButton->SetVisibility(ESlateVisibility::Visible);
	LowerButton->SetVisibility(ESlateVisibility::Visible);
	RightButton->SetVisibility(ESlateVisibility::Visible);*/
}


