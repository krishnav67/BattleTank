// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	// TODO prevent dual-speed due to dual control use
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we are Replacing Functionality
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"),*TankName,*MoveVelocityString);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	if (!LeftTrack || !RightTrack)
	{
		return;
	}
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
	// TODO prevent dual-speed due to dual control use
}