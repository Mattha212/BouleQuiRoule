// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/BoxComponent.h>
#include "GameFramework/Actor.h"
#include "SpecialRoad.h"
#include "SpeedRoad.generated.h"

UCLASS()
class BOULEQUIROULE_API ASpeedRoad : public ASpecialRoad
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASpeedRoad();
	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
