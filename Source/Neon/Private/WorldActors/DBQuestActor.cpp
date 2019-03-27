#include "DBQuestActor.h"
#include "Components/BoxComponent.h"
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
    SelectionCircle->SetMaterial(0, HighlightMaterial);
}

void ADBQuestActor::OnEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
    SelectionCircle->SetMaterial(0, DefaultMaterial);
}

void ADBQuestActor::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
    ANeonPlayerController* PC = Cast<ANeonPlayerController>(AI->GetWorld()->GetFirstPlayerController());
    ANeonCharacter* player = PC->NeonCharacter;
    float range = 350;
    float dist = FVector::Dist(player->GetActorLocation(), AI->GetOwner()->GetActorLocation());
    if (dist <= range)
    {

    }
}

