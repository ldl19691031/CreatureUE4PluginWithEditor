#include "CustomProceduralMesh.h"
#include "CreatureAnimStateMachine.h"
#include "EdGraph/EdGraphSchema.h"
UCreatureAnimStateMachine::UCreatureAnimStateMachine(){
	StateMachineGraph = NewObject<UAnimationStateMachineGraph>(UAnimationStateMachineGraph::StaticClass());

}

