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
	TArray<FActionTableData> array;
	auto dataTable = UResourceManagerLibrary::GetData()->ActionDataTable;
	dataTable->GetAllRows<FActionTableData>(TEXT(""), Abilities);
}

void UAbilityComponent::ShowAbilityRange(FString& name)
{
	ActiveAction = FindAbilityByName(name);
	TArray<FHitResult> HitResults;
	auto parent = GetOwner();
	FVector StartLocation =  parent->GetActorLocation();
	FVector EndLocation = parent->GetActorLocation();
	EndLocation.Z += 0;

	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(ActiveAction->Range);
	bool bHitSomething = GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);
	if (bHitSomething)
	{
		for (auto It = HitResults.CreateIterator(); It; It++)
		{
			auto actor = It->Actor;
			if (actor->ActorHasTag(ActiveAction->ObjectTag) || actor->ActorHasTag("GridBase")) {
				if (IAction::Execute_Highlight(It->Actor.Get(), ActiveAction->Name))
				{
					HighlighedObjects.Add(*It);
				}
			}
		}
	}
}

void UAbilityComponent::HideAbilityRange()
{
	ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PC) {
		PC->ActiveAction = nullptr;
		for (auto It = HighlighedObjects.CreateIterator(); It; It++)
		{
			IAction::Execute_Deactivate(It->Actor.Get());
		}
		HighlighedObjects.Empty();
	}

}

FActionTableData* UAbilityComponent::FindAbilityByName(FString name)
{
	for (auto data : Abilities)
	{
		if (data->Name == name) return data;
	}
	return nullptr;
}

void UAbilityComponent::InitAbilities()
{

}

void UAbilityComponent::GetActorsInRange(FString& name)
{
	ActiveAction = FindAbilityByName(name);
	TArray<FHitResult> HitResults;
	auto parent = GetOwner();
	FVector StartLocation = parent->GetActorLocation();
	FVector EndLocation = parent->GetActorLocation();
	EndLocation.Z += 0;

	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(ActiveAction->Range);
	GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);
}

