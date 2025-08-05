// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/BoxComponent.h>
#include "GameFramework/Actor.h"
#include "LaBoule.h"
#include "Obstacle.generated.h"

UCLASS()
class BOULEQUIROULE_API AObstacle : public AActor
{
	GENERATED_BODY()
	
	float m_HP;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UFUNCTION()
	void HandleHealthChange(float NewHealth);

public:	
	// Sets default values for this actor's properties
	AObstacle();
	float GetHealth() const { return m_HP; }
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UBoxComponent* m_BoxComponent;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_StaticMeshComponent;

	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
