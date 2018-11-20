// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionTooltip.h"
#include "CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UActionTooltip::SetData(FActionTableData& data)
{
	Title->SetText(FText::FromString(data.Name));
	Description->SetText(FText::FromString(data.Description));
	FString text = data.Cost + " Turns";
	Cooldown->SetText(FText::FromString(text));
	auto slot = Cast<UCanvasPanelSlot>(Energy);
	if(slot)
	{
		GLog->Log("SetSize");
		slot->SetSize(FVector2D(data.Cost * 38, 32));
	}
}
