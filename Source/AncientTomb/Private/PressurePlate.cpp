// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"

UPressurePlate::UPressurePlate()
{
}

void UPressurePlate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPressurePlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Something entered pressure plate")));
	if (OtherActor)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("ActorHasTag is %i"), OtherActor->ActorHasTag("CanTriggerPressurePlates")));
	}
	if (OtherActor && OtherActor->ActorHasTag("CanTriggerPressurePlates"))
	{
		ConnectedTombDoor->OpenDoor();
		NumPressureObjects += 1;
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("ActorHasTag is %i"), OtherActor->ActorHasTag("CanTriggerPressurePlates")));
	}
}

void UPressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Something exited pressure plate")));
	if (OtherActor)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("ActorHasTag is %i"), OtherActor->ActorHasTag("CanTriggerPressurePlates")));
	}
	if (OtherActor && OtherActor->ActorHasTag("CanTriggerPressurePlates"))
	{
		NumPressureObjects -= 1;
		if (NumPressureObjects == 0)
		{
			ConnectedTombDoor->CloseDoor();
		}
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("ActorHasTag is %i"), OtherActor->ActorHasTag("CanTriggerPressurePlates")));
	}
}

void UPressurePlate::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Started"));
	OnComponentBeginOverlap.AddDynamic(this, &UPressurePlate::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UPressurePlate::OnOverlapEnd);
}
