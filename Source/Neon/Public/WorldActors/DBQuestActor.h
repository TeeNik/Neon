#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBQuestActor.generated.h"

UCLASS()
class NEON_API ADBQuestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADBQuestActor();

protected:
	virtual void BeginPlay() override;
};
