#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TurretPawn.generated.h"

UCLASS()
class TOONTANKS_API ATurretPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	ATurretPawn();
	
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRange;

	class ATankPawn* TankPawnRef;
	FTimerHandle FireRateTimerHandle;
	float FireRate;

	void RotateTowardsTank() const;
	void CheckFireCondition();
	bool IsTankPawnInRange() const;
	
};
