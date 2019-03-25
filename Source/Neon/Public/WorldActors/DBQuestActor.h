#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DBQuestActor.generated.h"

class UMaterialInstance;
class UBoxComponent;

UCLASS()
class NEON_API ADBQuestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADBQuestActor();

    void OnBeginCursorOver(UPrimitiveComponent* TouchedComponent);
    void OnEndCursorOver(UPrimitiveComponent* TouchedComponent);
    void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

protected:
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* SelectionCircle;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UMaterialInstance* DefaultMaterial;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UMaterialInstance* HighlightMaterial;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UBoxComponent* BoxComponent;

private:
    //bool HasPlayerInRange
};
