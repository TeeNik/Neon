// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ResourceManagerLibrary.generated.h"

class UResourceManager;

UCLASS()
class NEON_API UResourceManagerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UResourceManagerLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Resource Manager")
	static UResourceManager* GetData();

	
};
