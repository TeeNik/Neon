#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "NeonCharacter.h"
#include "System/LocationManager.h"
#include "System/TurnManager.h"
#include "System/AbilityManager.h"
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
	AbilityManager = CreateDefaultSubobject<UAbilityManager>(TEXT("AbilityManager"));
}

void ANeonGameMode::BeginPlay()
{
	Super::BeginPlay();
}
 