// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last 

// Forward Declaration
class ATank;

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

	bool GetSightRayHitLocation(FVector &HOutitlocation) const;

	bool GetLookDirection(FVector2D ScreenLoation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

public:
	ATank* GetControlledTank() const;
};
