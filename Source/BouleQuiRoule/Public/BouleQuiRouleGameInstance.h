// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BouleQuiRouleGameInstance.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeLevel, FName, TargetLevel);

UCLASS()
class BOULEQUIROULE_API UBouleQuiRouleGameInstance : public UGameInstance
{
	GENERATED_BODY()


	void Init() override;

	UFUNCTION()
	void ChangeLevel(FName levelToLoad);

	UPROPERTY(EditAnywhere)
	FName TargetLevel;

public:
	UPROPERTY(EditAnywhere)
	FOnChangeLevel m_ChangeLevelEvent;

	UFUNCTION(BlueprintCallable)
	static UBouleQuiRouleGameInstance* GetGameInstance();

	UFUNCTION(BlueprintCallable)
	static UWorld* GetCurrentWorld();

	virtual void OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld) override;
	virtual void LoadComplete(const float LoadTime, const FString& MapName) override;


};
