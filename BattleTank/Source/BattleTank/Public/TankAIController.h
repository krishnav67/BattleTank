// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

//Forward Declaration
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

private:
	// How close the AI Tank can get
	float AcceptanceRadius = 3000;

protected:
	//call when game Starts
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};
