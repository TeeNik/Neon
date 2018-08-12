// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionWidget.h"


void UActionWidget::ClearButtons()
{
	for (UButton* button : ButtonArray) {
		button->OnClicked.Clear();
		button->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UActionWidget::ShowOnPosition(FVector2D& actorScreenLocation)
{
	SetPositionInViewport(actorScreenLocation + FVector2D(50, 50), true);
	SetVisibility(ESlateVisibility::Visible);
}

