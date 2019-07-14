#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthInfoWidget.generated.h"

class UProgressBar;
class UTextBlock;

UCLASS()
class NEON_API UHealthInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:

    FORCEINLINE uint32 GetID() { return ID; }
    FORCEINLINE void SetID(uint32& id) { ID = id; }

protected:

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ShieldBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;
	
private:

    UPROPERTY()
    uint32 ID;
};
