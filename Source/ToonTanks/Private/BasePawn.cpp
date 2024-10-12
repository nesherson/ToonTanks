#include "BasePawn.h"

#include "Components/CapsuleComponent.h"

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

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



