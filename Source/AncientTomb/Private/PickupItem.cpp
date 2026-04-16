// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupItem.h"

// Sets default values
APickupItem::APickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupItem::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APickupItem::OnOverlapBegin);
	//OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnOverlapBegin);
	//OnComponentEndOverlap.AddDynamic(this, &APickupItem::OnOverlapEnd);
}

void APickupItem::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Actor entered is %s"), *OtherActor-> GetClass() ->GetName()));
	}
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Item obtained")));
	if (OtherActor && OtherActor->IsA(AAncientTombCharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("Item obtained")));
		AAncientTombCharacter* overlapped_character = Cast<AAncientTombCharacter>(OtherActor);
		//OtherActor->AddToScore(ScoreValue);
		overlapped_character->AddToScore(ScoreValue);
		this->Destroy();
	}
}

// Called every frame
void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


