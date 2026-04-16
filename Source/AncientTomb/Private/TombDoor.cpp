// Fill out your copyright notice in the Description page of Project Settings.


#include "TombDoor.h"

// Sets default values
ATombDoor::ATombDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATombDoor::BeginPlay()
{
	Super::BeginPlay();
	OpenTarget = FindComponentByTag<USceneComponent>("Target");
	Destination = OpenTarget->GetComponentLocation();
	OriginalDestination = Destination;
	
	StartLocation = GetActorLocation();
	
	CloseDoor();
}

// Called every frame
void ATombDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!bReachedEnd)
	{
		InterpolateToTarget(DeltaTime);
	}
		
}

void ATombDoor::OpenDoor()
{
	bReachedEnd = false;
	Destination = OriginalDestination;
}

void ATombDoor::CloseDoor()
{
	bReachedEnd = false;
	Destination = StartLocation;
}
void ATombDoor::AddOneToTriggers()
{
	numCurrentTriggers += 1;
}
void ATombDoor::SubtractOneFromTriggers()
{
	numCurrentTriggers -= 1;
}
void ATombDoor::InterpolateToTarget(float DeltaTime)
{
	
	FVector current_location = GetActorLocation();
	
	bReachedEnd = false;
	SetActorLocation(FMath::VInterpConstantTo(current_location, Destination, DeltaTime, speed));
	
	if (FVector::Dist(current_location, Destination) <= 0.00001)
	{
		bReachedEnd = true;
	}
}



bool ATombDoor::CheckIfTriggersSatisfied()
{
	return numCurrentTriggers >= numRequiredTriggers;
}
