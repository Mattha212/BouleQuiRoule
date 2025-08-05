// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "LevelDataAsset.h"
#include "Portal.generated.h"

UCLASS()
class BOULEQUIROULE_API APortal : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* m_BoxComponent;

	UPROPERTY(EditAnywhere, Category= "Level")
	ULevelDataAsset* m_LevelList;

	UPROPERTY(EditAnywhere, Category = "Level")
	int32 m_LevelIndex;
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
