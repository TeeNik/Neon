#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Action/Action.h"
#include "DBQuestActor.generated.h"

class UMaterialInstance;
class UBoxComponent;

UCLASS()
class NEON_API ADBQuestActor : public AActor, public IAction
{
	GENERATED_BODY()
	
public:	
	ADBQuestActor();

    UFUNCTION(BlueprintCallable, Category = "Action")
    virtual void OnBeginCursorOver(UPrimitiveComponent* TouchedComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Action")
    virtual void OnEndCursorOver(UPrimitiveComponent* TouchedComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Action")
    virtual void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed) override;

    UFUNCTION(BlueprintCallable, Category = "Action")
    virtual void Deactivate() override;

    UFUNCTION(BlueprintCallable, Category = "Action")
    virtual bool Highlight(FString& AbilityName) override;

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
