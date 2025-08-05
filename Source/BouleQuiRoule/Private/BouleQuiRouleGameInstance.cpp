// Fill out your copyright notice in the Description page of Project Settings.


#include "BouleQuiRouleGameInstance.h"
#include <Kismet/GameplayStatics.h>

void UBouleQuiRouleGameInstance::Init()
{
	Super::Init();
	FScriptDelegate D;
	D.BindUFunction(this, "ChangeLevel");
	m_ChangeLevelEvent.Add(D);
}

void UBouleQuiRouleGameInstance::ChangeLevel(FName levelToLoad)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), *levelToLoad.ToString())
	UGameplayStatics::OpenLevel(this, levelToLoad);
}

UBouleQuiRouleGameInstance* UBouleQuiRouleGameInstance::GetGameInstance()
{
	FWorldContext* world = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	UBouleQuiRouleGameInstance* gameInstance = Cast<UBouleQuiRouleGameInstance>(UGameplayStatics::GetGameInstance(world->World()));
	return gameInstance;

}

UWorld* UBouleQuiRouleGameInstance::GetCurrentWorld()
{
	return GetGameInstance()->GetWorld();
}

void UBouleQuiRouleGameInstance::OnWorldChanged(UWorld* OldWorld, UWorld* NewWorld)
{
	Super::OnWorldChanged(OldWorld, NewWorld);
}

void UBouleQuiRouleGameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);
}
