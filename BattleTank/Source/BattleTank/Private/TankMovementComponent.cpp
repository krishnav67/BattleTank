// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Move Forward Scalling : %f"), Throw);
	
	// Self Made Pointer Controller
	if (!LeftTrack || !RightTrack)
	{
		UE_LOG(LogTemp, Warning, TEXT("Null value Found on LeftTrack and RightTrack"));
		return;
	}
	else
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);
	}
}