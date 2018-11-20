#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceManager.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class NEON_API UResourceManager : public UObject
{
	GENERATED_BODY()
	
public:
	UResourceManager(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	TArray<UClass*> SolusTreeBlueprints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	FVector SolusEssentialVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	FString SolusCoreFilePath;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource Manager")
	UDataTable* ActionDataTable;
	
};
