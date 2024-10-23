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

	void HandleDestruction();

protected:
	void RotateTurret(const FVector& LookAtTarget) const;
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess=true))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* BaseMeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* TurretMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;
};
