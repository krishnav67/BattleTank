// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	TankAmingComponent->Initialise(BarrelToSet, TurretToSet);
	Barrel = BarrelToSet;
	if (!Barrel)
	{
		return;
	}
}

void ATank::AimAt(FVector HitLocation)
{
	TankAmingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds);
	if (Barrel && isReloaded)
	{
		// Spawn a Projectile at Socket Location on the Barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}