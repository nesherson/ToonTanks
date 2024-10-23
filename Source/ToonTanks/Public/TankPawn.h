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
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();
	APlayerController* GetPlayerController() const;
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate;

	APlayerController* TankPlayerController;
	
	void Move(float Value);
	void Turn(float Value);
};
