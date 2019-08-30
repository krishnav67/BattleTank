// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankPlayerController.h"
#include"Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Not Possesing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Yeah We Got Player Controller %s"), *ControlledTank->GetName());
	}
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}