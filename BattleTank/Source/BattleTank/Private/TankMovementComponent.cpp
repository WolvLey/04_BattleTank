// Fill out your copyright notice in the Description page of Project Settings.
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TOOD prevent double-speed due to dual control use
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	UE_LOG(LogTemp, Warning, TEXT("Intend turn right throw: %f"), Throw)

		LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TOOD prevent double-speed due to dual control use
}