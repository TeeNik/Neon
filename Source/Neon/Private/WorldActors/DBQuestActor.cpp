#include "DBQuestActor.h"
#include "Components/BoxComponent.h"
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
    SelectionCircle->SetMaterial(0, HighlightMaterial);
}

void ADBQuestActor::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
    SelectionCircle->SetMaterial(0, DefaultMaterial);
}

void ADBQuestActor::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{

}

