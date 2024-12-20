#pragma once

#include "BasePawn.generated.h"

class UCapsuleComponent;

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
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* BaseMeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* TurretMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	UParticleSystem* DeathParticle;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;
};
