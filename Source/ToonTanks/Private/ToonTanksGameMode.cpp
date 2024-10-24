#include "ToonTanksGameMode.h"

#include "TankPawn.h"
#include "ToonTanksPlayerController.h"
#include "TurretPawn.h"
#include "Kismet/GameplayStatics.h"


void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	TankPawn = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(
		UGameplayStatics::GetPlayerController(this, 0));
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == TankPawn)
	{
		TankPawn->HandleDestruction();
		
		if (ToonTanksPlayerController)
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		
	}
	else if (ATurretPawn* DestroyedTurretPawn = Cast<ATurretPawn>(DeadActor))
	{
		DestroyedTurretPawn->HandleDestruction();
	}
}

