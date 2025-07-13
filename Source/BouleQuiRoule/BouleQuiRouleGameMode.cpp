// Copyright Epic Games, Inc. All Rights Reserved.

#include "BouleQuiRouleGameMode.h"
#include "BouleQuiRouleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABouleQuiRouleGameMode::ABouleQuiRouleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
