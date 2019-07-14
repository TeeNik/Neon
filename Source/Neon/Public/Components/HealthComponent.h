#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

struct Direction;
class UHealthComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnDataUpdate, UHealthComponent*);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEON_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	void TakeDamage(int& damage);
	void AddShield(int& value);
	void DamageShield(int& value);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE	int32 GetMaxHealth() { return MaxHealth; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE	int32 GetCurrentHealth() { return CurrentHealth; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE	int32 GetMaxShield() { return MaxShield; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE	int32 GetCurrentShield() { return CurrentShield; }

	Direction GetDefenceValue();

    UPROPERTY(BlueprintAssignable)
    FOnDeath Death;

	FOnDataUpdate OnDataUpdate;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 MaxHealth;
	int32 CurrentHealth;
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 MaxShield;
	int32 CurrentShield;
    
};
