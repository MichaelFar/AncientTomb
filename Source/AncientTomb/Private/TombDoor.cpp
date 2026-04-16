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
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("MyOwner is %s"), *MyOwner->GetActorNameOrLabel()));
	StartLocation = GetActorLocation();
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("StartLocation is %s"), *StartLocation.ToString()));
	CloseDoor();
}

// Called every frame
void ATombDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	InterpolateToTarget(DeltaTime);
}

void ATombDoor::OpenDoor()
{
	Destination = OriginalDestination;
}

void ATombDoor::CloseDoor()
{
	Destination = StartLocation;
}
void ATombDoor::InterpolateToTarget(float DeltaTime)
{
	//FVector destination = OpenTarget->GetComponentLocation();
	FVector current_location = GetActorLocation();
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("ComponentLocation is %s"), *Destination.ToString()));
	bReachedEnd = false;
	SetActorLocation(FMath::VInterpConstantTo(current_location, Destination, DeltaTime, speed));
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Destination is + %s"), *Destination.ToString()));
	if (FVector::Dist(current_location, Destination) <= 0.00001)
	{
		bReachedEnd = true;
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Reached End")));
	}
}
