// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionWidget.h"

void UActionWidget::ClearButtons()
{
	LeftButton->OnClicked.Clear();
	UpperButton->OnClicked.Clear();
	LowerButton->OnClicked.Clear();
	RightButton->OnClicked.Clear();
	LeftButton->SetVisibility(ESlateVisibility::Visible);
	UpperButton->SetVisibility(ESlateVisibility::Visible);
	LowerButton->SetVisibility(ESlateVisibility::Visible);
	RightButton->SetVisibility(ESlateVisibility::Visible);
}
