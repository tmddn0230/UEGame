// Copyright Epic Games, Inc. All Rights Reserved.

#include "Framework/UEGameGameMode.h"
#include "Framework/UEGameCharacter.h"
#include "Framework/UEGamePlayerController.h"
#include "UObject/ConstructorHelpers.h"

AUEGameGameMode::AUEGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/UEGame/Blueprints/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AUEGamePlayerController::StaticClass();

}
