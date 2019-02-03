#pragma once
#include "CoreMinimal.h"
#include "InputCore/Classes/InputCoreTypes.h"
#include "UObject/Interface.h"
#include "Action.generated.h"

class UPrimitiveComponent;

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UAction : public UInterface
{
	GENERATED_BODY()
};

class IAction
{
	GENERATED_BODY()

public:
	bool isInRange;

	virtual void OnBeginCursorOver(UPrimitiveComponent* TouchedComponent) {}

	virtual void OnEndCursorOver(UPrimitiveComponent* TouchedComponent) {}

	virtual void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed) {}

	virtual void Deactivate() {}

	virtual bool Highlight(FString& AbilityName) { return false; }
};


