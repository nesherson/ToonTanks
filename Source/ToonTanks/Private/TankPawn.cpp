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
	bAlive = true;
}

void ATankPawn::BeginPlay()
{
	Super::BeginPlay();

	TankPlayerController = Cast<APlayerController>(GetController());
}

void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TankPlayerController)
	{
		FHitResult HitResult;
		TankPlayerController->GetHitResultUnderCursor(ECC_Visibility,
			false,
			HitResult);

		RotateTurret(HitResult.ImpactPoint);
	}
}

void ATankPawn::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	bAlive = false;
}

APlayerController* ATankPawn::GetPlayerController() const
{
	return TankPlayerController;
}

void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATankPawn::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATankPawn::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATankPawn::Fire);
}

void ATankPawn::Move(float Value)
{
	FVector DeltaVector = FVector::ZeroVector;
	DeltaVector.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	
	AddActorLocalOffset(DeltaVector, true);
}

void ATankPawn::Turn(float Value)
{
	FRotator DeltaRotator = FRotator::ZeroRotator;
	DeltaRotator.Yaw = Value * UGameplayStatics::GetWorldDeltaSeconds(this) * TurnRate;

	AddActorLocalRotation(DeltaRotator, true);
}
