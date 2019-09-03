// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last 

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:
	// called when Game Starts
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector &Hitlocation) const;

public:
	ATank* GetControlledTank() const;
};
