// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceManager.generated.h"

UCLASS(BlueprintType)
class NEON_API UResourceManager : public UObject
{
	GENERATED_BODY()
	
public:
	UResourceManager(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	TArray<UClass*> SolusTreeBlueprints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	UTexture2D* SolusT2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	FVector SolusEssentialVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	FString SolusCoreFilePath;
	
	
};
