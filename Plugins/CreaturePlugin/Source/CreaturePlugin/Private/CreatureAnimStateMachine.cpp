#include "CustomProceduralMesh.h"
#include "CreatureAnimStateMachine.h"
#include "CreatureAnimTransition.h"
#include "EdGraph/EdGraphSchema.h"
UCreatureAnimStateMachine::UCreatureAnimStateMachine(){
	//StateMachineGraph = NewObject<UCreatureStateMachineGraph>(UCreatureStateMachineGraph::StaticClass());

}

void UCreatureAnimStateMachine::SetCondition(FString ConditionName, bool Flag)
{
	//����״̬

	for (int i = 0; i < TransitionConditionList.Num();i++)
	{
		if (TransitionConditionList[i].TransitionName == ConditionName)
		{
			TransitionConditionList[i].TransitionFlag = Flag;
		}
	}
	//�ж��Ƿ���Ҫת��
	CurrentState->CheckCondition();
}

void UCreatureAnimStateMachine::InitStateMachine()
{
	if (CurrentState != nullptr&&CurrentState != RootState->TransitionList[0]->TargetState)
	{
		CurrentState->bIsCurrentState = false;//���ó�ʼ�ڵ�״̬������Debug
	}
	//�󶨶�����ʼ���β�¼���MeshComponent����֧��AnimStart/AnimEndת��
	if (OwningComponent!=nullptr)
	{
		OwningComponent->CreatureAnimationStartEvent.AddDynamic(this, &UCreatureAnimStateMachine::OnAnimStart);
		OwningComponent->CreatureAnimationEndEvent.AddDynamic(this, &UCreatureAnimStateMachine::OnAnimEnd);
	}
	//��ʱʹ�ã�ֱ�ӴӸ��ڵ�������һ���ڵ�
	CurrentState = RootState->TransitionList[0]->TargetState;
	CurrentState->bIsCurrentState = true;
	CurrentState->BeginState();
}

void UCreatureAnimStateMachine::OnAnimStart(float frame)
{
	//SetCondition(FString(TEXT("AnimationStart")),true);
	//SetCondition(FString(TEXT("AnimationEnd")), false);
}

void UCreatureAnimStateMachine::OnAnimEnd(float frame)
{
	//SetCondition(FString(TEXT("AnimationStart")), false);
	//SetCondition(FString(TEXT("AnimationEnd")), true);
	CurrentState->AnimationEnd();
}

