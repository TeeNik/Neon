// Fill out your copyright notice in the Description page of Project Settings.
#include "Action.h"
#include "Neon.h"

void IAction::SendDeactivate()
{
	ANeonPlayerController* NC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	NC->CloseWidget();
}
