// Fill out your copyright notice in the Description page of Project Settings.

#include "GridBase.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "NeonPlayerController.h"
#include "Action/ActionTableData.h"
#include "System/ResourceManagerLibrary.h"


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

	state = Down;
}

// Called when the game starts or when spawned
void AGridBase::BeginPlay()
{
	Super::BeginPlay();

	BoxComp->OnBeginCursorOver.AddDynamic(this, &AGridBase::OnBeginCursorOver);
	BoxComp->OnEndCursorOver.AddDynamic(this, &AGridBase::OnEndCursorOver);
	BoxComp->OnClicked.AddDynamic(this, &AGridBase::OnClicked);
}


void AGridBase::SetWidgetSettings(UActionWidget* widget) {
	/*this->BoxComp->SetRenderCustomDepth(true);

	widget->ClearButtons();
	widget->SetVisibility(ESlateVisibility::Visible);

	UDataTable* actionTable = UResourceManagerLibrary::GetData()->ActionDataTable;
	FActionTableData* topData = actionTable->FindRow<FActionTableData>(TEXT("Top"), TEXT(""));
	FActionTableData* middleData = actionTable->FindRow<FActionTableData>(TEXT("Middle"), TEXT(""));
	FActionTableData* downData = actionTable->FindRow<FActionTableData>(TEXT("Down"), TEXT(""));

	auto buttons = widget->ButtonArray;
	if (state == Top) {
		buttons[Upper]->OnClicked.AddDynamic(this, &AGridBase::MoveDown);
		buttons[Upper]->SetVisibility(ESlateVisibility::Visible);
		widget->SetButtonImage(Upper, downData->Icon);;
	}
	else if(state == Middle){
		buttons[Upper]->OnClicked.AddDynamic(this, &AGridBase::MoveToTop);
		buttons[Right]->OnClicked.AddDynamic(this, &AGridBase::MoveDown);
		buttons[Upper]->SetVisibility(ESlateVisibility::Visible);
		buttons[Right]->SetVisibility(ESlateVisibility::Visible);
		widget->SetButtonImage(Upper, topData->Icon);
		widget->SetButtonImage(Right, downData->Icon);
	}
	else {
		buttons[Upper]->OnClicked.AddDynamic(this, &AGridBase::MoveToTop);
		buttons[Right]->OnClicked.AddDynamic(this, &AGridBase::MoveToMiddle);
		buttons[Upper]->SetVisibility(ESlateVisibility::Visible);
		buttons[Right]->SetVisibility(ESlateVisibility::Visible);
		widget->SetButtonImage(Upper, topData->Icon);
		widget->SetButtonImage(Right, middleData->Icon);
	}*/
}

void AGridBase::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if(isInRange)
	{
		MeshComp->SetCustomDepthStencilValue(253);
		//MeshComp->SetRenderCustomDepth(true);
	}
}

void AGridBase::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if(isInRange)
	{
		MeshComp->SetCustomDepthStencilValue(252);
	}
}

void AGridBase::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (ButtonPressed.GetFName() == "LeftMouseButton" && isInRange) {
		ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
		if (PC) {
			FString actionName = PC->NeonCharacter->GetAbilityConponent()->ActiveAction;
			if (actionName.Equals(TEXT("Top")))
				MoveToTop();
			else if (actionName.Equals(TEXT("Down")))
				MoveDown();
			else if (actionName.Equals(TEXT("MoveTo"))) {
				GridLocationComp->SetStatus(Player);
				PC->NeonCharacter->GetMotionComponent()->MoveToGrid(this);
			}
				

		}
	}
}

void AGridBase::Deactivate_Implementation() {
	MeshComp->SetRenderCustomDepth(false);
	isInRange = false;
}

void AGridBase::MoveToMiddle()
{
	Move(state == Down ? Middle : -Middle);
	state = Middle;	
}

void AGridBase::MoveToTop()
{
	Move(state == Down ? Top : Middle);
	state = Top;
}

void AGridBase::MoveDown()
{
	Move(state == Top ? -Top : -Middle);
	state = Down;
}

void AGridBase::Highlight_Implementation()
{
	MeshComp->SetRenderCustomDepth(true);
	isInRange = true;
}

void AGridBase::Move(float value)
{
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	FVector targetPos = GetActorLocation() + FVector(0, 0, value);
	UKismetSystemLibrary::MoveComponentTo(RootComponent, targetPos, FRotator(0.0f, 0.0f, 0.0f), false, false, 3, false, EMoveComponentAction::Type::Move, LatentInfo);
}


