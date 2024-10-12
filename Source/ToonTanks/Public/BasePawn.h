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
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess=true))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* BaseMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	UStaticMeshComponent* TurretMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components",meta = (AllowPrivateAccess=true))
	USceneComponent* ProjectileSpawnPoint;

public:	
	virtual void Tick(float DeltaTime) override;
};
