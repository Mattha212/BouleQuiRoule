// Fill out your copyright notice in the Description page of Project Settings.

#include "BouleController.h"
#include "EnhancedInputComponent.h"
#include "LaBoule.h" 

ABouleController::ABouleController()
{
}



void ABouleController::MoveForward(const FInputActionValue& InputValue)
{
	if (ALaBoule* pawn = Cast<ALaBoule>(GetPawn())) {
		pawn->MoveForward(InputValue);
	}
}

void ABouleController::MoveSide(const FInputActionValue& InputValue)
{
	if (ALaBoule* pawn = Cast<ALaBoule>(GetPawn())) {
		pawn->MoveRight(InputValue);
	}
}

void ABouleController::Dash(const FInputActionValue& InputValue)
{
	if (ALaBoule* pawn = Cast<ALaBoule>(GetPawn())) {
		pawn->Dash(InputValue);
	}
}

void ABouleController::Jump(const FInputActionValue& InputValue)
{
	if (ALaBoule* pawn = Cast<ALaBoule>(GetPawn())) {
		pawn->Jump(InputValue);
	}
}

void ABouleController::Look(const FInputActionValue& InputValue) {

}


void ABouleController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LP = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Sub =
			LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Sub->AddMappingContext(m_IMC_RollingBall, 1);
		}
	}

	//APawn* MyPawn = GetPawn();
	//if (MyPawn && GetStartSpot())
	//{
	//	FRotator StartRot = GetStartSpot()->GetActorRotation();
	//	MyPawn->SetActorRotation(StartRot);
	//}

}

void ABouleController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(m_IA_MoveForward, ETriggerEvent::Triggered, this, &ABouleController::MoveForward);
		EIC->BindAction(m_IA_MoveSide, ETriggerEvent::Triggered, this, &ABouleController::MoveSide);
		EIC->BindAction(m_IA_Dash, ETriggerEvent::Completed, this, &ABouleController::Dash);
		EIC->BindAction(m_IA_Jump, ETriggerEvent::Completed, this, &ABouleController::Jump);
		EIC->BindAction(m_IA_Look, ETriggerEvent::Completed, this, &ABouleController::Look);
	}
}
