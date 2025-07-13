// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/BoxComponent.h>
#include "GameFramework/Actor.h"
#include "LaBoule.h"
#include "SpecialRoad.generated.h"

UCLASS()
class BOULEQUIROULE_API ASpecialRoad : public AActor
{
	GENERATED_BODY()


	
public:	
	// Sets default values for this actor's properties
	ASpecialRoad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UBoxComponent* m_BoxComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_StaticMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
