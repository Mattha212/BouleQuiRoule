// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Components/SphereComponent.h>
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
	UCameraComponent* m_Camera;

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

public:
	// Sets default values for this pawn's properties
	ALaBoule();

	UFUNCTION()
	void MoveForward(const FInputActionValue& Value);

	UFUNCTION()
	void MoveRight(const FInputActionValue& Value);

	UFUNCTION()
	void Dash(const FInputActionValue& Value);
	
	UFUNCTION()
	void Jump(const FInputActionValue& Value);

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

	FVector GetVelocity() {
		return m_SphereComponent->GetPhysicsLinearVelocity();
	}

};
