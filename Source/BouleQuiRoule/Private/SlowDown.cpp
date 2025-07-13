// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowDown.h"

void ASlowDown::OnActorHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ALaBoule* boule = Cast<ALaBoule>(OtherActor);
    if (IsValid(boule)) {
        boule->SlowDown();
    }
}

void ASlowDown::BeginPlay()
{
	Super::BeginPlay();
	m_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASlowDown::OnActorHit);
}
