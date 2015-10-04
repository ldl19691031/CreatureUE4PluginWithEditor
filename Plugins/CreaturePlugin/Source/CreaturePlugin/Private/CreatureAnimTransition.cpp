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

void UCreatureAnimTransition::AnimationEndTranslate()
{
	//���ȼ�鵱ǰת���Ƿ�ΪAnimationEnd
	if (TransitionConditions[0].TransitionName == FString(TEXT("AnimationEnd")))
	{
		AnimStateMachine->CurrentState->bIsCurrentState = false;
		AnimStateMachine->CurrentState = TargetState;

		AnimStateMachine->CurrentState->BeginState();
		AnimStateMachine->CurrentState->bIsCurrentState = true;
	}
}
