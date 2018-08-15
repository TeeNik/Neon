// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityComponent.h"

UAbilityComponent::UAbilityComponent()
{

}

void UAbilityComponent::SetIcons()
{
	//widget->bu
}

void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	/*ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		widget = PC->ActionWidget;
	}*/
	
}
