// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdventureGame_SEM2GameMode.h"
#include "AdventureGame_SEM2Character.h"
#include "UObject/ConstructorHelpers.h"

AAdventureGame_SEM2GameMode::AAdventureGame_SEM2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
