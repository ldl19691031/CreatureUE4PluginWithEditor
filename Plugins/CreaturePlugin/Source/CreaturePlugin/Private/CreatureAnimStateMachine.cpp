#include "CustomProceduralMesh.h"
#include "CreatureAnimStateMachine.h"
#include "EdGraph/EdGraphSchema.h"
#include "CreatureStateMachineGraph.h"
UCreatureAnimStateMachine::UCreatureAnimStateMachine(){
	StateMachineGraph = NewObject<UCreatureStateMachineGraph>(UCreatureStateMachineGraph::StaticClass());

}

