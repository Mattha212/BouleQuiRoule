// Fill out your copyright notice in the Description page of Project Settings.


#include "LaBoule.h"
#include <InputTriggers.h>
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
// Sets default values
ALaBoule::ALaBoule()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = m_SphereComponent;
	m_SphereComponent->SetSimulatePhysics(true);
	m_SphereComponent->SetMassOverrideInKg(NAME_None, 10);
	m_SphereComponent->SetSimulatePhysics(true);
	m_SphereComponent->SetLinearDamping(1.5f);   // évite glissement
	m_SphereComponent->SetAngularDamping(1.0f);  // évite rotation infinie


	m_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	m_StaticMeshComponent->SetupAttachment(m_SphereComponent);

	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	m_SpringArm->SetupAttachment(m_SphereComponent);
	m_SpringArm->TargetArmLength = 400.f;
	m_SpringArm->bEnableCameraLag = true;
	m_SpringArm->CameraLagSpeed = 3.f;
	m_SpringArm->bInheritYaw = false;
	m_SpringArm->bInheritRoll = false;
	m_SpringArm->bInheritPitch = false;

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(m_SpringArm, USpringArmComponent::SocketName);

	m_MoveForce = 50000;
	m_AccumulationValue = 1.0f;
	m_MinAccumulationValue = 1.f;
	m_MaxAccumulationValue = 3.f;
	m_MaxNormeVelocity = 1000.0f;
}

// Called when the game starts or when spawned
void ALaBoule::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALaBoule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector ForceDirection = FVector::ZeroVector;

	if (Controller)
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotationMatrix RotMatrix(Rotation);

		FVector Forward = RotMatrix.GetScaledAxis(EAxis::X);
		FVector Right = RotMatrix.GetScaledAxis(EAxis::Y);

		ForceDirection = (Forward * m_InputValueForward + Right * m_InputValueSide).GetClampedToMaxSize(1.0f);
	}

	if (!ForceDirection.IsNearlyZero())
	{
		m_AccumulationValue = FMath::Clamp(m_AccumulationValue + 0.02f, m_MinAccumulationValue, m_MaxAccumulationValue);
		m_SphereComponent->AddForce(ForceDirection * m_MoveForce * m_AccumulationValue);
	}
	else
	{
		m_AccumulationValue = m_MinAccumulationValue;
		FVector Velocity = m_SphereComponent->GetPhysicsLinearVelocity();
		FVector DampingForce = -Velocity * 0.2f;
		m_SphereComponent->AddForce(DampingForce);
	}
	m_InputValueForward = 0.f;
	m_InputValueSide = 0.f;

}

// Called to bind functionality to input
void ALaBoule::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ALaBoule::MoveForward(const FInputActionValue& InputValue)
{
	float Value = InputValue.Get<float>();
	m_InputValueForward = Value;
}

void ALaBoule::MoveRight(const FInputActionValue& InputValue)
{
	float Value = InputValue.Get<float>();
	m_InputValueSide = Value;
}

void ALaBoule::Dash(const FInputActionValue& Value)
{
	auto velocity = m_SphereComponent->GetPhysicsLinearVelocity();
	m_SphereComponent->SetPhysicsLinearVelocity(FVector::Zero());
	m_SphereComponent->SetPhysicsLinearVelocity((velocity * 10.0f).GetClampedToMaxSize(m_MaxNormeVelocity));
}

void ALaBoule::Jump(const FInputActionValue& Value)
{
	m_SphereComponent->AddImpulse(FVector(0.0f, 0.0f, 35000.0f));
}

void ALaBoule::Speedy()
{

	m_SphereComponent->SetPhysicsLinearVelocity((m_SphereComponent->GetPhysicsLinearVelocity() * 10.0f).GetClampedToMaxSize(m_MaxNormeVelocity));
}

void ALaBoule::SlowDown() 
{
	m_SphereComponent->SetPhysicsLinearVelocity((m_SphereComponent->GetPhysicsLinearVelocity() * 0.2f));
}

void ALaBoule::Rebound()
{
	auto velocity = -m_SphereComponent->GetPhysicsLinearVelocity();
	m_SphereComponent->SetPhysicsLinearVelocity(FVector::Zero());
	m_SphereComponent->SetPhysicsLinearVelocity(velocity*10.0f);
}
