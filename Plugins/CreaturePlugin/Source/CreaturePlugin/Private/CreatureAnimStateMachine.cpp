#include "CustomProceduralMesh.h"
#include "CreatureAnimStateMachine.h"
#include "EdGraph/EdGraphSchema.h"
UCreatureAnimStateMachine::UCreatureAnimStateMachine(){
	//StateMachineGraph = NewObject<UCreatureStateMachineGraph>(UCreatureStateMachineGraph::StaticClass());

}

void UCreatureAnimStateMachine::SetCondition(FString ConditionName, bool Flag)
{
	for (FCreatureTransitionCondition condition:TransitionConditionList)
	{
		if (condition.TransitionName==ConditionName)
		{
			condition.TransitionFlag = Flag;
		}
	}
}

void UCreatureAnimStateMachine::InitStateMachine()
{
	RootState->BeginState();
}

