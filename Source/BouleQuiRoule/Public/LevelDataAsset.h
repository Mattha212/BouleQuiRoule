// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LevelDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BOULEQUIROULE_API ULevelDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Level")
	TArray<FName> m_LevelName;
};
