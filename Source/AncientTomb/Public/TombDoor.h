// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TombDoor.generated.h"

UCLASS()
class ANCIENTTOMB_API ATombDoor : public AActor
{
	GENERATED_BODY()
private:
	
public:	
	// Sets default values for this actor's properties
	ATombDoor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* OpenTarget;
	FVector StartLocation;
	FVector Destination;
	FVector OriginalDestination;
	UPROPERTY(VisibleAnywhere)
	bool bReachedEnd = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShouldMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isOpen = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OpenDoor();
	void CloseDoor();
	void InterpolateToTarget(float DeltaTime);

};
