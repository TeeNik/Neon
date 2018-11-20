#include "Weapon.h"
#include "WorldActors/WeaponProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

AWeapon::AWeapon()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::Shoot(FRotator& rotation, FName& targetTag, int32& dmg)
{
	FVector start = MeshComp->GetSocketLocation("Muzzle");
	AWeaponProjectile* projectile = GetWorld()->SpawnActor<AWeaponProjectile>(Projectile, start, rotation/* + FRotator(25,0,0)*/);
	GLog->Log(FString::FromInt(dmg));
	projectile->Init(targetTag, dmg);
}
