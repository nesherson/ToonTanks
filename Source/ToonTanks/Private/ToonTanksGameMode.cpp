#include "ToonTanksGameMode.h"

#include "TankPawn.h"
#include "ToonTanksPlayerController.h"
#include "TurretPawn.h"
#include "Kismet/GameplayStatics.h"

AToonTanksGameMode::AToonTanksGameMode()
{
	StartDelay = 3.f;
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
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

void AToonTanksGameMode::HandleGameStart()
{
	TankPawn = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(
		UGameplayStatics::GetPlayerController(this, 0));

	if (ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true);

		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false);
	}
}


