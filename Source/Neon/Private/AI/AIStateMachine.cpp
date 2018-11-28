#include "AIStateMachine.h"
#include "AIState.h"
#include "UtilsLibrary.h"
#include "EnergyComponent.h"
#include "GameFramework/Actor.h"

UAIStateMachine::UAIStateMachine()
{

}

void UAIStateMachine::BeginPlay()
{
	Super::BeginPlay();
}

void UAIStateMachine::NextState(AIState* state)
{
	if (CurrentState != NULL) {
		delete CurrentState;
	}
	CurrentState = state;
	CurrentState->Execute();
}

void UAIStateMachine::EndTurn()
{
	UEnergyComponent* energyComp = UUtilsLibrary::GetRelativeComponent<UEnergyComponent>(this);
	energyComp->EndTurn();
	if (CurrentState != NULL) {
		delete CurrentState;
	}
}

