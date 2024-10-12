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
	Speed = 1;
}

void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATankPawn::Move);
}

void ATankPawn::Move(float Value)
{
	FVector DeltaVector = FVector(0);
	DeltaVector.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	
	AddActorLocalOffset(DeltaVector);
	// UE_LOG(LogTemp, Display, TEXT("ATankPawn::Move -> %f"), test);	
}
