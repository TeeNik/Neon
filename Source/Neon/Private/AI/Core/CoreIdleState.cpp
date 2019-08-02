#include "CoreIdleState.h"

UCoreIdleState::UCoreIdleState() {
	Name = "CoreIdleState";
}

void UCoreIdleState::Execute() {
    AI->EndTurn();
}