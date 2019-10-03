// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last 

// Forward Declaration
class ATank;

/**
* Responsible for helping the player aim.
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()	

protected:
	// called when Game Starts
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category=Setup)
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector &HOutitlocation) const;

	bool GetLookDirection(FVector2D ScreenLoation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;


};
