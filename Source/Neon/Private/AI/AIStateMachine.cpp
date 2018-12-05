#include "AIStateMachine.h"
#include "AIState.h"
#include "UtilsLibrary.h"
#include "EnergyComponent.h"
#include "GameFramework/Actor.h"
#include "IdleState.h"
#include "ShootState.h"

UAIStateMachine::UAIStateMachine()
{
	isAwake = false;
}

void UAIStateMachine::BeginPlay()
{
	Super::BeginPlay();
}

void UAIStateMachine::StartTurn()
{
	GLog->Log("AI Start");
	AIState* state;
	if (isAwake) {
		FName tag = TEXT("Player");
		state = new ShootState(this, tag);
	}
	else {
		state = new IdleState(this);
	}
	NextState(state);
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
		CurrentState = NULL;
	}
}

void UAIStateMachine::SetAwake(bool value)
{
	isAwake = value;
}
