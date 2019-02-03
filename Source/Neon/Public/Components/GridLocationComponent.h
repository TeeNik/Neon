#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridLocationComponent.generated.h"

enum class GridLocationStatus
{
	Empty,
	Player,
	Enemy
};

enum GridBaseState {
	Down = 0,
	Middle = 50,
	Top = 100,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UGridLocationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGridLocationComponent();

	FORCEINLINE void SetStatus(GridLocationStatus newStatus) { status = newStatus; }
	FORCEINLINE const GridLocationStatus& GetStatus() const { return status; };

	GridBaseState State;

protected:
	virtual void BeginPlay() override;

private:
	GridLocationStatus status;
};
