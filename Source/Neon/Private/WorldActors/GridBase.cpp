// Fill out your copyright notice in the Description page of Project Settings.

#include "GridBase.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "NeonPlayerController.h"
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

/*FActionData AGridBase::GetActionList_Implementation()
{
	FActionData actionData;
	actionData.Cost = 25;
	actionData.Description = FString(TEXT("Some Description"));
//	actionData.ActionFunction = &AGridBase::MoveToTop;
	GLog->Log(UResourceManagerLibrary::GetData()->SolusCoreFilePath);

	return actionData;
}*/

void AGridBase::SetWidgetSettings(UActionWidget* widget) {
	this->BoxComp->SetRenderCustomDepth(true);

	widget->ClearButtons();

	widget->SetVisibility(ESlateVisibility::Visible);
	auto buttons = widget->ButtonArray;
	if (state == Top) {
		buttons[Upper]->OnClicked.AddDynamic(this, &AGridBase::MoveDown);
		buttons[Upper]->SetVisibility(ESlateVisibility::Visible);
	}
	else if(state == Middle){
		buttons[Upper]->OnClicked.AddDynamic(this, &AGridBase::MoveToTop);
		buttons[Right]->OnClicked.AddDynamic(this, &AGridBase::MoveDown);
		buttons[Upper]->SetVisibility(ESlateVisibility::Visible);
		buttons[Right]->SetVisibility(ESlateVisibility::Visible);
	}
	else {
		buttons[Upper]->OnClicked.AddDynamic(this, &AGridBase::MoveToTop);
		buttons[Right]->OnClicked.AddDynamic(this, &AGridBase::MoveToMiddle);
		buttons[Upper]->SetVisibility(ESlateVisibility::Visible);
		buttons[Right]->SetVisibility(ESlateVisibility::Visible);
	}
}

void AGridBase::OnBeginCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	MeshComp->SetRenderCustomDepth(true);
}

void AGridBase::OnEndCursorOver_Implementation(UPrimitiveComponent* TouchedComponent)
{
	if(!isActive)
		MeshComp->SetRenderCustomDepth(false);
}

void AGridBase::OnClicked_Implementation(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	GLog->Log(ButtonPressed.GetFName().ToString());
	if (ButtonPressed.GetFName() == "LeftMouseButton" && !isActive) {
		ANeonPlayerController* PC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController());
		if (PC) {
			PC->ClickedActor = this;
			FVector2D screenLocation;
			PC->ProjectWorldLocationToScreen(GetActorLocation(), screenLocation);
			PC->ActionWidget->ShowOnPosition(screenLocation);
			SetWidgetSettings(PC->ActionWidget);
		}
	}
}

void AGridBase::Deactivate_Implementation() {
	MeshComp->SetRenderCustomDepth(false);
}

void AGridBase::MoveToMiddle()
{
	Move(state == Down ? Middle : -Middle);
	state = Middle;	
	//ANeonPlayerController NC = Cast<ANeonPlayerController>(GetWorld()->GetFirstPlayerController()
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

void AGridBase::Move(float value)
{
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	FVector targetPos = GetActorLocation() + FVector(0, 0, value);
	UKismetSystemLibrary::MoveComponentTo(RootComponent, targetPos, FRotator(0.0f, 0.0f, 0.0f), false, false, 3, false, EMoveComponentAction::Type::Move, LatentInfo);
}

