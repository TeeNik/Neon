#include "AIStateMachine.h"
#include "AIState.h"

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

