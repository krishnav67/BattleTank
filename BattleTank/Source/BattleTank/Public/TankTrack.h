// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set Maximum Driving force, and apply force to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	// Set Throttle Between -1 and +1
	UFUNCTION(BlueprintCallable, Category=Input)
	void SetThrottle(float Throttle);

	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackmaxDrivingForce = 400000; //Assume 40 tonne tank, and 1kg accelaration
	
};
