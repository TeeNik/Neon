#pragma once
#include "CoreMinimal.h"
#include "InputCore/Classes/InputCoreTypes.h"
#include "UObject/Interface.h"
#include "Action.generated.h"

class UPrimitiveComponent;

UINTERFACE(BlueprintType)
class NEON_API UAction : public UInterface
{
	GENERATED_BODY()
};

class NEON_API IAction
{
	GENERATED_BODY()

public:
	bool isInRange;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void OnBeginCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void OnEndCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed); 

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	void Deactivate();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Action")
	bool Highlight(FString& AbilityName);
};


