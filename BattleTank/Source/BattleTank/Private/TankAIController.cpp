// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Soory We Never Got Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Yeah We GOT Player Tank : %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO Move towards Player

	// Aim towards the player
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}