// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS001GameMode.h"
#include "FPS001Character.h"
#include "UObject/ConstructorHelpers.h"

AFPS001GameMode::AFPS001GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	

}
