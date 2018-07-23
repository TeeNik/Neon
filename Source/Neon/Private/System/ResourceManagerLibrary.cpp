// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManagerLibrary.h"




UResourceManagerLibrary::UResourceManagerLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

UResourceManager* UResourceManagerLibrary::GetData() {
	UResourceManager* DataInstance = Cast<UResourceManager>(GEngine->GameSingleton);
	if (!DataInstance) return NULL;
	if (!DataInstance->IsValidLowLevel()) return NULL;
	return DataInstance;
}
