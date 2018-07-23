// Fill out your copyright notice in the Description page of Project Settings.

#include "GridBase.h"
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
	//actionData.SetSomeInt(44);
	actionData.SomeInt = 25;
	actionData.Description = FString(TEXT("Some Description"));

	GLog->Log(UResourceManagerLibrary::GetData()->SolusCoreFilePath);

	return actionData;
}
