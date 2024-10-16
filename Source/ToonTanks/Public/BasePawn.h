#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

protected:
	void RotateTurret(const FVector& LookAtTarget) const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess=true))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* BaseMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* TurretMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	USceneComponent* ProjectileSpawnPoint;
};
