// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpecialRoad.h"
#include "SlowDown.generated.h"

/**
 * 
 */
UCLASS()
class BOULEQUIROULE_API ASlowDown : public ASpecialRoad
{
	GENERATED_BODY()
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

};
