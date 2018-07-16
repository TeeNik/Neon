// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "NeonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANeonGameMode::ANeonGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ANeonPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BP_CameraPawn"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ANeonGameMode::BeginPlay()
{
	/*GLog->Log("Here");
	for (int i = 0; i < 64; ++i)
	{
		FVector Location(125*(i%8), 125 * (i / 8), 176);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		GetWorld()->SpawnActor<AGridBase>(Location, Rotation, SpawnInfo);
	}*/
}
