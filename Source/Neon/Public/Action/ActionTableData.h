#pragma once
#include "Engine/DataTable.h"
#include "ActionTableData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct NEON_API FActionTableData : public FTableRowBase
{
	GENERATED_BODY()

public:
	
	FActionTableData() {
		Cost = 2;
		Description = TEXT("None");
	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	int32 Cost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	float  Range;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	int32 Cooldown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	FName ObjectTag;
};

USTRUCT(BlueprintType)
struct NEON_API FActionOwnerTableData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	FString ActionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Data")
	FString OwnerTags;

};
