#include "AIStateMachine.h"
#include "AIState.h"
#include "UtilsLibrary.h"
#include "EnergyComponent.h"
#include "GameFramework/Actor.h"
#include "IdleState.h"
#include "ShootState.h"
#include "MovementState.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "Engine/World.h"

UAIStateMachine::UAIStateMachine()
{
}

void UAIStateMachine::BeginPlay()
{
	Super::BeginPlay();

	if (FirstState == NULL) {
		GLog->Log("FirstState == NULL");
	}
}

void UAIStateMachine::StartTurn()
{
	GLog->Log("AI Start");
	GetWorld()->GetTimerManager().ClearTimer(Timer);
	UAIState* state;
	state = NewObject<UAIState>(this, FirstState);
	NextState(state);
}

void UAIStateMachine::NextState(UAIState* state)
{
	if (CurrentState != NULL) {
		delete CurrentState;
	}
	state->Init(this);
	CurrentState = state;
	GLog->Log(state->Name);
	CurrentState->Execute();
}

void UAIStateMachine::EndTurn()
{
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &UAIStateMachine::EndTurnImpl, 5, false);
}

void UAIStateMachine::EndTurnImpl()
{
	UEnergyComponent* energyComp = UUtilsLibrary::GetRelativeComponent<UEnergyComponent>(this);
	energyComp->EndTurn();
	if (CurrentState != NULL) {
		delete CurrentState;
		CurrentState = NULL;
	}
}