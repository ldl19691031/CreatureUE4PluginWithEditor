#include "CustomProceduralMesh.h"
#include "CreatureAnimTransition.h"
#include "CreatureAnimStateMachine.h"
bool UCreatureAnimTransition::Translate()
{
	for (FCreatureTransitionCondition condition : TransitionConditions)
	{
		int32 index;
		if (AnimStateMachine->TransitionConditionList.Find(condition, index) == true){
			if (AnimStateMachine->TransitionConditionList [index].TransitionFlag!= condition.TransitionFlag)
			{
				return false;
			}else
				continue;
		}
		
	}
	//���е�������ƥ�䣬������ת
	AnimStateMachine->CurrentState->bIsCurrentState = false;
	AnimStateMachine->CurrentState = TargetState;
	//�п��ܻ�����ת��Ҫ���
	/*TargetState->CheckCondition();*/
	AnimStateMachine->CurrentState->BeginState();
	AnimStateMachine->CurrentState->bIsCurrentState = true;
	return true;
}
