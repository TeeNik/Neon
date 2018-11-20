#include "WeaponProjectile.h"
#include "Components/HealthComponent.h"
#include "System/UtilsLibrary.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AWeaponProjectile::AWeaponProjectile()
{
	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	RootComponent = ParticleComp;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComp->SetupAttachment(RootComponent);
	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AWeaponProjectile::OnBeginOverlap);
	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComp->InitialSpeed = 1000;
	MovementComp->MaxSpeed = 1000;
	MovementComp->ProjectileGravityScale = 0;
}

void AWeaponProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaponProjectile::Init(FName& targetTag, int32& dmg)
{
	TargetTag = targetTag;
	Damage = dmg;
}

void AWeaponProjectile::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->ActorHasTag(TargetTag)) {
		if (Damage != 0)
		{
			UHealthComponent* health = UUtilsLibrary::GetComponentByClass<UHealthComponent>(OtherActor);
			health->TakeDamage(Damage);
		}
		Destroy();
	}
}