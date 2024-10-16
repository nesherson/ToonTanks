#include "BasePawn.h"

#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;
	BaseMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMeshComp->SetupAttachment(CapsuleComp);
	TurretMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMeshComp->SetupAttachment(BaseMeshComp);
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMeshComp);
}

void ABasePawn::RotateTurret(const FVector& LookAtTarget) const
{
	const FVector ToTarget = LookAtTarget - TurretMeshComp->GetComponentLocation();
	const FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	
	TurretMeshComp->SetWorldRotation(
		FMath::RInterpTo(TurretMeshComp->GetComponentRotation(),
		LookAtRotation,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		22.5f));
}



