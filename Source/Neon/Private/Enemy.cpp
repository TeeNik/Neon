// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


AEnemy::AEnemy()
{
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	MeshComp->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	MeshComp->OnClicked.AddDynamic(this, &AEnemy::OnClicked);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::OnClicked(UPrimitiveComponent * Component, FKey key)
{
	GLog->Log("keked");
}

