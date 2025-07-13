// Fill out your copyright notice in the Description page of Project Settings.


#include "ReboundRoad.h"

AReboundRoad::AReboundRoad() {

}

void AReboundRoad::OnActorHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ALaBoule* boule = Cast<ALaBoule>(OtherActor);
	if (IsValid(boule)) {
		boule->Rebound();
	}
}

void AReboundRoad::BeginPlay()
{
	Super::BeginPlay();
	m_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AReboundRoad::OnActorHit);
}

void AReboundRoad::Tick(float DeltaTime)
{
}

