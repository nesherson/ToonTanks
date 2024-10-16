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
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATurretPawn::CheckFireCondition, 2.f, true);
}
 
void ATurretPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateTowardsTank();
}

void ATurretPawn::RotateTowardsTank() const
{
	if (IsTankPawnInRange())
		RotateTurret(TankPawnRef->GetActorLocation());
}

void ATurretPawn::CheckFireCondition()
{
	if (IsTankPawnInRange())
		Fire();
}

bool ATurretPawn::IsTankPawnInRange() const
{
	if (!TankPawnRef)
		return false;
	
	return FVector::Dist(GetActorLocation(), TankPawnRef->GetActorLocation()) <= FireRange;
}
