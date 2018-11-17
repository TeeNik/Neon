#include "AIStateMachine.h"

UAIStateMachine::UAIStateMachine()
{

}

void UAIStateMachine::BeginPlay()
{
	Super::BeginPlay();
}

void UAIStateMachine::NextState(AIState& state)
{
	CurrentState = state;
	CurrentState.Execute();
}

