#include "DBQuestActor.h"
#include "Components/BoxComponent.h"

ADBQuestActor::ADBQuestActor()
{
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

void ADBQuestActor::BeginPlay()
{
	Super::BeginPlay();
	
    BoxComponent->OnBeginCursorOver.AddDynamic(this, &ADBQuestActor::OnBeginCursorOver);
    BoxComponent->OnEndCursorOver.AddDynamic(this, &ADBQuestActor::OnEndCursorOver);
    BoxComponent->OnClicked.AddDynamic(this, &ADBQuestActor::OnClicked);

}