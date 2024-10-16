#include "TurretPawn.h"

#include "TankPawn.h"
#include "Kismet/GameplayStatics.h"

ATurretPawn::ATurretPawn()
{
	FireRange = 700.f;
}

void ATurretPawn::BeginPlay()
{
	Super::BeginPlay();
	
	TankPawnRef = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}
 
void ATurretPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateTowardsTank();
}


void ATurretPawn::RotateTowardsTank() const
{
	if (!TankPawnRef)
		return;
	
	const float Distance = FVector::Dist(GetActorLocation(), TankPawnRef->GetActorLocation());

	if (Distance <= FireRange)
		RotateTurret(TankPawnRef->GetActorLocation());
}

