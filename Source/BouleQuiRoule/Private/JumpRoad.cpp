// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpRoad.h"

void AJumpRoad::OnActorHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ALaBoule* boule = Cast<ALaBoule>(OtherActor);
	if (IsValid(boule)) {
		boule->ForcedJump();
	}
}

void AJumpRoad::BeginPlay()
{
	m_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AJumpRoad::OnActorHit);
}
