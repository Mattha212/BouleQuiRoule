// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Camera.generated.h"

/**
 * 
 */
UCLASS()
class BOULEQUIROULE_API UCamera : public UCameraComponent
{
	GENERATED_BODY()
	
public:
	UCamera();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
