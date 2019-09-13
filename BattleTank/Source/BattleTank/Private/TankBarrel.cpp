// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("Here We Have Run Elevate() : %f"), DegreesPerSeconds);
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
}