// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxSpeedPerSecond = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;

};
