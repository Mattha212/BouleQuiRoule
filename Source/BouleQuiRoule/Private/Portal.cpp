// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include <LaBoule.h>
#include <Kismet/GameplayStatics.h>
#include <BouleQuiRouleGameInstance.h>

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
	m_BoxComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	ensure(m_LevelList != nullptr);
	ensure(m_LevelList->m_LevelName.IsValidIndex(m_LevelIndex));
	m_BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APortal::OnOverlapBegin);
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ALaBoule* boule = Cast<ALaBoule>(OtherActor);
	if (IsValid(boule)) {
		UBouleQuiRouleGameInstance* gameInstance = Cast<UBouleQuiRouleGameInstance>(GetGameInstance());
		if (IsValid(gameInstance)) {
			FName LevelToLoad = m_LevelList->m_LevelName[m_LevelIndex];
			UE_LOG(LogTemp, Log, TEXT("%s"), *LevelToLoad.ToString())
			gameInstance->m_ChangeLevelEvent.Broadcast(LevelToLoad);
		}

	}
}


