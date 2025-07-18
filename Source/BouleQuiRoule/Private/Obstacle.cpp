// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = m_BoxComponent;

	m_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	m_StaticMeshComponent->SetupAttachment(m_BoxComponent);

	m_HP = 100.0f;
}

void AObstacle::HandleHealthChange(float NewHealth)
{
	m_HP -= NewHealth;
	UE_LOG(LogTemp, Warning, TEXT("%f"), m_HP)
	if (m_HP <= 0)
		Destroy();
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	m_BoxComponent->OnComponentHit.AddDynamic(this, &AObstacle::OnActorHit);
	OnHealthChanged.AddDynamic(this, &AObstacle::HandleHealthChange);
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacle::OnActorHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit) {

	ALaBoule* boule = Cast<ALaBoule>(OtherActor);
	if (IsValid(boule)) {
		
		float velocityToValue = boule->GetVelocity().Size() / 10.0f;
		OnHealthChanged.Broadcast(velocityToValue);

	}

}