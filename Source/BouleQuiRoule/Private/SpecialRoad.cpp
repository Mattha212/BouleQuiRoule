// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialRoad.h"

// Sets default values
ASpecialRoad::ASpecialRoad()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = m_BoxComponent;

	m_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	m_StaticMeshComponent->SetupAttachment(m_BoxComponent);
}

// Called when the game starts or when spawned
void ASpecialRoad::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpecialRoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
