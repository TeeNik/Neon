#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "NeonCharacter.h"
#include "System/LocationManager.h"
#include "System/TurnManager.h"
#include "System/AbilityManager.h"
#include "System/InfoWidgetManager.h"
#include "UObject/ConstructorHelpers.h"
#include "LevelInfoWidget.h"
#include "Engine/World.h"

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

	LevelWidget = CreateWidget<ULevelInfoWidget>(GetWorld(), LevelWidgetBP);

	AbilityManager = CreateDefaultSubobject<UAbilityManager>(TEXT("AbilityManager"));
	RootComponent = AbilityManager;
	LocationManager = CreateDefaultSubobject<ULocationManager>(TEXT("LocationManager"));
	InfoWidgetManager = CreateDefaultSubobject<UInfoWidgetManager>(TEXT("InfoWidgetManager"));

	//last
	TurnManager = CreateDefaultSubobject<UTurnManager>(TEXT("TurnManager"));
}

void ANeonGameMode::BeginPlay()
{
	Super::BeginPlay();
}
 