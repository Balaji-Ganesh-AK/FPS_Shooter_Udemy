// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UR_FPS_ShooterGameMode.h"
#include "UR_FPS_ShooterHUD.h"
#include "UR_FPS_ShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUR_FPS_ShooterGameMode::AUR_FPS_ShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUR_FPS_ShooterHUD::StaticClass();
}
