// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedRoad.h"

// Sets default values
ASpeedRoad::ASpeedRoad()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void ASpeedRoad::OnActorHit(UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    ALaBoule* boule = Cast<ALaBoule>(OtherActor);
    if (IsValid(boule)) {
        boule->Speedy();
    }
}

// Called when the game starts or when spawned
void ASpeedRoad::BeginPlay()
{
	Super::BeginPlay();
    m_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpeedRoad::OnActorHit);
}

// Called every frame
void ASpeedRoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

