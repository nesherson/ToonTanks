#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AToonTanksGameMode();
	void ActorDied(AActor* DeadActor);

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

protected:
	virtual void BeginPlay() override;

private:
	class ATankPawn* TankPawn;
	class AToonTanksPlayerController* ToonTanksPlayerController;
	float StartDelay;

	void HandleGameStart();
};
