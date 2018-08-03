// Fill out your copyright notice in the Description page of Project Settings.

#include "GridBase.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
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
}

FActionData AGridBase::GetActionList_Implementation()
{
	GLog->Log("Action of GridBase");
	FActionData actionData;
	actionData.Cost = 25;
	actionData.Description = FString(TEXT("Some Description"));
//	actionData.ActionFunction = &AGridBase::MoveToTop;
	GLog->Log(UResourceManagerLibrary::GetData()->SolusCoreFilePath);

	return actionData;
}

void AGridBase::SetWidgetSettings_Implementation(UActionWidget* widget) {
	widget->ClearButtons();
	if (state == Top) {
		widget->UpperButton->OnClicked.AddDynamic(this, &AGridBase::MoveDown);
	}
	else if(state == Middle){
		widget->UpperButton->OnClicked.AddDynamic(this, &AGridBase::MoveToTop);
		widget->RightButton->OnClicked.AddDynamic(this, &AGridBase::MoveDown);
	}
	else {
		widget->UpperButton->OnClicked.AddDynamic(this, &AGridBase::MoveToTop);
		widget->RightButton->OnClicked.AddDynamic(this, &AGridBase::MoveToMiddle);
	}
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

void AGridBase::Move(float value)
{
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	FVector targetPos = GetActorLocation() + FVector(0, 0, value);
	UKismetSystemLibrary::MoveComponentTo(RootComponent, targetPos, FRotator(0.0f, 0.0f, 0.0f), false, false, 3, false, EMoveComponentAction::Type::Move, LatentInfo);
}

