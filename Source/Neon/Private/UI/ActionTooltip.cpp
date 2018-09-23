// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionTooltip.h"
#include "CanvasPanelSlot.h"


void UActionTooltip::SetData(FText title, FText desc, FText cost, int32 energy)
{
	Title->SetText(title);
	Description->SetText(desc);
	Cost->SetText(cost);
	auto slot = Cast<UCanvasPanelSlot>(Energy);
	if(slot)
	{
		slot->SetSize(FVector2D(energy * 38, 32));
	}
}
