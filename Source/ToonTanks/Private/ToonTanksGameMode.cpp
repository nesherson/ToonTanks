#include "ToonTanksGameMode.h"

#include "TankPawn.h"
#include "ToonTanksPlayerController.h"
#include "TurretPawn.h"
#include "Kismet/GameplayStatics.h"

AToonTanksGameMode::AToonTanksGameMode()
{
	StartDelay = 3.f;
	TargetTurrets = 0;
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

		GameOver(false);
	}
	else if (ATurretPawn* DestroyedTurretPawn = Cast<ATurretPawn>(DeadActor))
	{
		DestroyedTurretPawn->HandleDestruction();
		--TargetTurrets;

		if (TargetTurrets == 0)
		{
			GameOver(true);
		}
	}
}

void AToonTanksGameMode::HandleGameStart()
{
	TargetTurrets = GetTargetTurretCount();
	TankPawn = Cast<ATankPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(
		UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

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

int32 AToonTanksGameMode::GetTargetTurretCount() const
{
	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(this, ATurretPawn::StaticClass(), Towers);

	return Towers.Num();
}


