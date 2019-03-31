#include "DBQuestActor.h"
#include "Components/BoxComponent.h"
#include "NeonGameMode.h"
#include "NeonPlayerController.h"
#include "NeonCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstance.h"

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

void ADBQuestActor::OnBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
    if (isInRange) {
        SelectionCircle->SetMaterial(0, HighlightMaterial);
    }
}

void ADBQuestActor::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
    if (isInRange) {
        SelectionCircle->SetMaterial(0, DefaultMaterial);
    }
}

void ADBQuestActor::Deactivate()
{
    isInRange = false;
    SelectionCircle->SetMaterial(0, DefaultMaterial);
}

bool ADBQuestActor::Highlight(FString& AbilityName)
{
    isInRange = true;
    return true;
}

void ADBQuestActor::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
    if (isInRange) {
        ANeonGameMode* GM = Cast<ANeonGameMode>(GetWorld()->GetAuthGameMode());
        //Add event to level manager
    }
}

