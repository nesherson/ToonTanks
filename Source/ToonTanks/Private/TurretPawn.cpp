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
	
	TankPawn = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATurretPawn::CheckFireCondition, 2.f, true);
}
 
void ATurretPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateTowardsTank();
}

void ATurretPawn::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATurretPawn::RotateTowardsTank() const
{
	if (IsTankPawnInRange())
	{
		RotateTurret(TankPawn->GetActorLocation());
	}
}

void ATurretPawn::CheckFireCondition()
{
	if (!TankPawn)
	{
		return;
	}
	
	if (IsTankPawnInRange() && TankPawn->bAlive)
	{
		Fire();
	}
}

bool ATurretPawn::IsTankPawnInRange() const
{
	if (!TankPawn)
	{
		return false;
	}
	
	return FVector::Dist(GetActorLocation(), TankPawn->GetActorLocation()) <= FireRange;
}
