#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TankPawn.generated.h"

UCLASS()
class TOONTANKS_API ATankPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	ATankPawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed;


	void Move(float Value);
};
