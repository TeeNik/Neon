// Fill out your copyright notice in the Description page of Project Settings.

#include "GridBase.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "NeonPlayerController.h"
#include "Components/EnergyComponent.h"
#include "Components/AbilityComponent.h"
#include "Components/MotionComponent.h"
#include "System/UtilsLibrary.h"
#include "NeonGameMode.h"


// Sets default values
AGridBase::AGridBase()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetRelativeScale3D(FVector(1, 1, 0.01));
	BoxComp->SetBoxExtent(FVector(62,62,32));
	BoxComp->SetVisibility(true);
	RootComponent = BoxComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetRelativeScale3D(FVector(1.25,1.25,0.01));
	MeshComp->SetupAttachment(RootComponent);

	PlaneComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneComp"));
	PlaneComp->SetupAttachment(RootComponent);

	GridLocationComp = CreateDefaultSubobject<UGridLocationComponent>(TEXT("GridLocationComp"));

	State = Down;
}

// Called when the game starts or when spawned
void AGridBase::BeginPlay()
{
	Super::BeginPlay();

	PlaneComp->OnBeginCursorOver.AddDynamic(this, &AGridBase::OnBeginCursorOver);
	PlaneComp->OnEndCursorOver.AddDynamic(this, &AGridBase::OnEndCursorOver);
	PlaneComp->OnClicked.AddDynamic(this, &AGridBase::OnClicked);
}

void AGridBase::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if(isInRange)
	{
		PlaneComp->SetMaterial(0, ActiveMaterial);
	}
}

void AGridBase::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if(isInRange)
	{
		PlaneComp->SetMaterial(0, DisableMaterial);
	}
}

void AGridBase::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" && isInRange) {
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if (EC) {
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Name;
			if (actionName == TopAbility)
				MoveToTop();
			else if (actionName == DownAbility)
				MoveDown();
			else if (actionName == MoveAbility) {
				//TODO Status
				GridLocationComp->SetStatus(GridLocationStatus::Player);
				UMotionComponent* motion = UUtilsLibrary::GetRelativeComponent<UMotionComponent>(EC);
				motion->MoveToGrid(this);
			}
			else if(actionName.Equals(TEXT("Cover")))
			{			
				auto cover = GM->GetLocationManager()->GetCoverInfo(this);
			}
			EC->SpendEnergy(actionComp->ActiveAction->Cost);
		}
	}
}

void AGridBase::Deactivate_Implementation() {
	PlaneComp->SetVisibility(false);
	PlaneComp->SetMaterial(0, DisableMaterial);
	isInRange = false;
}

void AGridBase::MoveToMiddle()
{
	Move(State == Down ? Middle : -Middle);
	State = Middle;	
}

void AGridBase::MoveToTop()
{
	Move(State == Down ? Top : Middle);
	State = Top;
}

void AGridBase::MoveDown()
{
	Move(State == Top ? -Top : -Middle);
	State = Down;
}

bool AGridBase::Highlight_Implementation(FString& abilityName)
{
	if (abilityName == TopAbility && State == Top || abilityName == DownAbility && State == Down)
		return false;
	
	PlaneComp->SetVisibility(true);
	isInRange = true;
	return true;
}

void AGridBase::Move(float value)
{
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	FVector targetPos = GetActorLocation() + FVector(0, 0, value);
	UKismetSystemLibrary::MoveComponentTo(RootComponent, targetPos, FRotator(0.0f, 0.0f, 0.0f), false, false, 3, false, EMoveComponentAction::Type::Move, LatentInfo);
}


