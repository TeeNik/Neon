#include "AbilityComponent.h"
#include "System/ResourceManagerLibrary.h"
#include "NeonPlayerController.h"
#include "Ability/Ability.h"
#include "System/AbilityManager.h"
#include "Action/Action.h"
#include "Action/ActionTableData.h"
#include "System/ResourceManager.h"
#include "Engine/World.h"
#include "NeonGameMode.h"
#include "DrawDebugHelpers.h"

UAbilityComponent::UAbilityComponent()
{

}

void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	InitAbilities();
}

void UAbilityComponent::ShowAbilityRange(FString& name)
{
	SetActiveAction(name);
	TArray<FHitResult> HitResults = GetActorsInRange(ActiveAction->Data->Range);
	for (auto It = HitResults.CreateIterator(); It; It++)
	{
		auto actor = It->Actor;
		if (actor->ActorHasTag(ActiveAction->Data->ObjectTag) || actor->ActorHasTag("GridBase")) {
			IAction* action = Cast<IAction>(It->GetActor());
			if (action != NULL && action->Highlight(name)) {
				HighlighedObjects.Add(*It);
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
			IAction* action = Cast<IAction>(It->GetActor());
			if (action != NULL) {
				action->Deactivate();
			}
		}
		HighlighedObjects.Empty();
	}

}

UAbility* UAbilityComponent::FindAbilityByName(FString& name)
{
	for (auto ability : Abilities)
	{
		if (ability->Data->Name == name) return ability;
	}
	return nullptr;
}

void UAbilityComponent::InitAbilities()
{
	auto dataTable = UResourceManagerLibrary::GetData()->ActionDataTable;
	TArray<FActionTableData*> abilityDatas;
	dataTable->GetAllRows<FActionTableData>(TEXT(""), abilityDatas);
	ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
	UAbilityManager* AM = GM->GetAbilityManager();
	for(int i = 0; i < abilityDatas.Num(); ++i)
	{
		UAbility* base = AM->GetAbility(abilityDatas[i]->Name);
		if (base == nullptr) continue;
		Abilities.Add(base);
	}
}

TArray<FHitResult> UAbilityComponent::GetActorsInRange(float radius)
{
	TArray<FHitResult> HitResults;
	auto parent = GetOwner();
	FVector StartLocation = parent->GetActorLocation();
	FVector EndLocation = parent->GetActorLocation();
	EndLocation.Z += 0;

	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(radius);
	GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);
	DrawDebugSphere(GetWorld(), StartLocation, radius, 50, FColor::Purple, true, 2);
	return HitResults;
}

void UAbilityComponent::SetActiveAction(FString& name)
{
	ActiveAction = FindAbilityByName(name);
}

