// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Components/SphereComponent.h>
#include "Camera.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "LaBoule.generated.h"

UCLASS()
class BOULEQUIROULE_API ALaBoule : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USphereComponent* m_SphereComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	UCamera* m_Camera;

	UPROPERTY(EditAnywhere)
	USceneComponent* m_CameraRoot;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* m_SpringArm;

	float m_InputValueForward;
	float m_InputValueSide;

	float m_MoveForce;
	float m_AccumulationValue;
	float m_MaxAccumulationValue;
	float m_MinAccumulationValue;
	float m_MaxNormeVelocity;
	FVector CurrentInput;

	bool m_IsJumping;
	bool m_CanDash;
	float m_DashCoolDown;
	float m_LastDashTime;
public:
	// Sets default values for this pawn's properties
	ALaBoule();

	USceneComponent* GetCamera() { return m_CameraRoot; }

	UFUNCTION()
	void MoveForward(const FInputActionValue& Value);

	UFUNCTION()
	void MoveRight(const FInputActionValue& Value);

	UFUNCTION()
	void Dash(const FInputActionValue& Value);
	
	UFUNCTION()
	void Jump(const FInputActionValue& Value);

	void ForcedJump();
	void Speedy();
	void Rebound();
	void SlowDown();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector GetLinearVelocity();

	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);

};
