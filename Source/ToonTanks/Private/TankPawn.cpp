#include "TankPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATankPawn::ATankPawn()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
	Speed = 100;
	TurnRate = 65; 
}

void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATankPawn::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATankPawn::Turn);
}

void ATankPawn::Move(float Value)
{
	FVector DeltaVector = FVector::ZeroVector;
	DeltaVector.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	
	AddActorLocalOffset(DeltaVector, true);
	// UE_LOG(LogTemp, Display, TEXT("ATankPawn::Move -> %f"), test);	
}

void ATankPawn::Turn(float Value)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	DeltaRotator.Yaw = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;

	AddActorLocalRotation(DeltaRotator, true);
}
