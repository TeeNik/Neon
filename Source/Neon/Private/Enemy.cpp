// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


AEnemy::AEnemy()
{
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetRelativeScale3D(FVector(1,1,2));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComp->OnClicked.AddDynamic(this, &AEnemy::OnClicked);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::OnClicked(UPrimitiveComponent * Component, FKey key)
{
	GLog->Log("render");
	IsSelected = !IsSelected;
	MeshComp->SetRenderCustomDepth(IsSelected);
}

