// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "BouleController.generated.h"

UCLASS()
class BOULEQUIROULE_API ABouleController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* m_IMC_RollingBall;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_IA_MoveForward;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_IA_MoveSide;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_IA_Dash;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* m_IA_Jump;

public:
	ABouleController();

	void MoveForward(const FInputActionValue& InputValue);
	void MoveSide(const FInputActionValue& InputValue);
	void Dash(const FInputActionValue& InputValue);
	void Jump(const FInputActionValue& InputValue);

protected:
	virtual void BeginPlay() override ;
	virtual void SetupInputComponent() override;
};
