#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InfoWidgetManager.generated.h"

class UHealthInfoWidget;
class UHealthComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UInfoWidgetManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	UInfoWidgetManager();

	UPROPERTY(EditDefaultsOnly, Category = "Manager")
	TSubclassOf<UHealthInfoWidget> InfoWidgetClass;

	void RegisterEvent(UHealthComponent*);

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<UHealthInfoWidget*> InfoWidgets;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* comp);

};
