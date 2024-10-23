#include "ToonTanksGameMode.h"

#include "TankPawn.h"
#include "TurretPawn.h"
#include "Kismet/GameplayStatics.h"


void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	TankPawn = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == TankPawn)
	{
		APlayerController* TankPlayerController = TankPawn->GetPlayerController();
		
		TankPawn->HandleDestruction();
		
		if (TankPlayerController)
		{
			TankPawn->DisableInput(TankPlayerController);
			TankPlayerController->bShowMouseCursor = false;
		}
	}
	else if (ATurretPawn* DestroyedTurretPawn = Cast<ATurretPawn>(DeadActor))
	{
		DestroyedTurretPawn->HandleDestruction();
	}
}

