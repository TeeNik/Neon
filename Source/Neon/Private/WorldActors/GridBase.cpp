#include "GridBase.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "NeonPlayerController.h"
#include "Components/EnergyComponent.h"
#include "Components/AbilityComponent.h"
#include "Components/MotionComponent.h"
#include "Components/WeaponComponent.h"
#include "System/UtilsLibrary.h"
#include "NeonGameMode.h"
#include "UI/ActionWidget.h"
#include "Components/StaticMeshComponent.h"
#include "Action/ActionTableData.h"
#include "Ability/Ability.h"
#include "Components/BoxComponent.h"
#include "Components/GridLocationComponent.h"
#include "System/TurnManager.h"
#include "System/LocationManager.h"

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

	GridLocationComp->State = Down;
}

void AGridBase::BeginPlay()
{
	Super::BeginPlay();

	PlaneComp->OnBeginCursorOver.AddDynamic(this, &AGridBase::OnBeginCursorOver);
	PlaneComp->OnEndCursorOver.AddDynamic(this, &AGridBase::OnEndCursorOver);
	PlaneComp->OnClicked.AddDynamic(this, &AGridBase::OnClicked);
}

void AGridBase::OnBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if(isInRange)
	{
		//PlaneComp->SetMaterial(0, ActiveMaterial);
	}
}

void AGridBase::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if(isInRange)
	{
		//PlaneComp->SetMaterial(0, DisableMaterial);
	}
}

void AGridBase::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" && isInRange) {
		ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
		UEnergyComponent* EC = GM->GetTurnManager()->GetCurrentEC();
		if (EC) {
			UAbilityComponent* actionComp = UUtilsLibrary::GetRelativeComponent<UAbilityComponent>(EC);
			FString actionName = actionComp->ActiveAction->Data->Name;
			
			//TODO
			if (actionComp->ActiveAction->Data->ObjectTag != "GridBase") return;
			GM->OnPlayerAbilityCall.Broadcast(this);
			EC->SpendEnergy(actionComp->ActiveAction->Data->Cost);
		}
	}
}

void AGridBase::Deactivate() {
	//PlaneComp->SetVisibility(false);
	//PlaneComp->SetMaterial(0, DisableMaterial);
	PlaneComp->SetRenderCustomDepth(false);
	isInRange = false;
}


bool AGridBase::Highlight(FString& abilityName)
{
	if (abilityName == TopAbility && GridLocationComp->State == Top || abilityName == DownAbility && GridLocationComp->State == Down)
	return false;

	//PlaneComp->SetVisibility(true);
	PlaneComp->SetRenderCustomDepth(true);
	isInRange = true;
	return true;
}

void AGridBase::MoveToMiddle()
{
	Move(GridLocationComp->State == Down ? Middle : -Middle);
	GridLocationComp->State = Middle;
}

void AGridBase::MoveToTop()
{
	Move(GridLocationComp->State == Down ? Top : Middle);
	GridLocationComp->State = Top;
}

void AGridBase::MoveDown()
{
	Move(GridLocationComp->State == Top ? -Top : -Middle);
	GridLocationComp->State = Down;
}

void AGridBase::Move(float value)
{
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	FVector targetPos = GetActorLocation() + FVector(0, 0, value);
	UKismetSystemLibrary::MoveComponentTo(RootComponent, targetPos, FRotator(0.0f, 0.0f, 0.0f), false, false, 3, false, EMoveComponentAction::Type::Move, LatentInfo);
}


