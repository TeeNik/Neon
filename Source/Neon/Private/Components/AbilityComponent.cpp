// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilityComponent.h"
#include "System/ResourceManagerLibrary.h"
#include "NeonPlayerController.h"
#include "Action/ActionTableData.h"
#include "Action/Action.h"

UAbilityComponent::UAbilityComponent()
{

}


void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		Widget = PC->ActionWidget;
	}
	auto dataTable = UResourceManagerLibrary::GetData()->ActionDataTable;
	dataTable->GetAllRows<FActionTableData>(TEXT(""), Actions);
	Widget->InitButtons(Actions);
}

void UAbilityComponent::ShowAbilityRange(FName name)
{
	auto ability = Actions[0];
	TArray<FHitResult> HitResults;
	auto parent = GetOwner();
	FVector StartLocation =  parent->GetActorLocation();
	FVector EndLocation = parent->GetActorLocation();
	EndLocation.Z += 0;

	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(350);
	bool bHitSomething = GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);
	if (bHitSomething)
	{
		for (auto It = HitResults.CreateIterator(); It; It++)
		{
			auto actor = It->Actor;
			if (actor->ActorHasTag(ability->ObjectTag)) {
				auto action = Cast<IAction>(actor);
				IAction::Execute_Highlight(It->Actor.Get());
			}
		}
	}
	FVector CenterOfSphere = ((EndLocation - StartLocation) / 2) + StartLocation;
}

