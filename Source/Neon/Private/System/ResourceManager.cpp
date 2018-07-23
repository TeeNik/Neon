// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManager.h"

UResourceManager::UResourceManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SolusCoreFilePath = "E:/Solus";

	SolusEssentialVector = FVector(9000, 0, 0);
}



