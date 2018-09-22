// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "NeonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANeonGameMode::ANeonGameMode()
{
	PlayerControllerClass = ANeonPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BP_CameraPawn"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	LocationManager = CreateDefaultSubobject<ULocationManager>(TEXT("LocationManager"));
	TurnManager = CreateDefaultSubobject<UTurnManager>(TEXT("TurnManager"));
}

void ANeonGameMode::BeginPlay()
{
	Super::BeginPlay();
}
 