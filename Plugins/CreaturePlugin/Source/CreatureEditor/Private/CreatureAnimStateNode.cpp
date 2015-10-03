#include "CreatureEditorPCH.h"
#include "CreatureAnimStateNode.h"
#include "SGraphNode.h"
#include "CreatureAnimTransitionNode.h"
#include "CreatureAnimStateMachine.h"

void UCreatureAnimStateNode::OnRenameNode(const FString& NewName)
{
	AnimName = NewName;
}

bool UCreatureAnimStateNode::CanUserDeleteNode() const
{
	return true;
}

FText UCreatureAnimStateNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(AnimName);
}
#ifdef WITH_EDITOR
void UCreatureAnimStateNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.ChangeType == EPropertyChangeType::ValueSet&&GetGraph()!=nullptr)
	{
		GetGraph()->NotifyGraphChanged();
	}
	

}
#endif


void UCreatureAnimStateNode::Compile()
{
	CompiledState->AnimStateName = AnimName;

	CompiledState->TransitionList.Empty();
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin->Direction == EEdGraphPinDirection::EGPD_Output)
		{
			for (UEdGraphPin* TargetPin : Pin->LinkedTo)
			{
				//���任��Ϣ����������State
				if (UCreatureAnimTransitionNode* TargetNode = Cast<UCreatureAnimTransitionNode>(TargetPin->GetOwningNode()))
				{
					UCreatureAnimTransition* Tran = NewObject<UCreatureAnimTransition>(CompiledState->GetOuter());
					FCreatureTransitionCondition TranCondition = FCreatureTransitionCondition(TargetNode->TransitionCondition, TargetNode->TransitionFlag);
					Tran->TargetState = TargetNode->TransitionTargetNode->CompiledState;
					INT16 Index= Tran->TransitionConditions.AddUnique(TranCondition);
					//�ٴ����һ��任Condition��������޸���TranCondition������Ч�����
					Tran->TransitionConditions[Index].TransitionFlag = TranCondition.TransitionFlag;
					Tran->AnimStateMachine = CompiledState->AnimStateMachine;

					//��״̬��ע�ᵱǰ״̬ת����Ϣ
					Tran->AnimStateMachine->TransitionConditionList.AddUnique(TranCondition);
					CompiledState->TransitionList.Add(Tran);
				}
				

			}
		}

	}
	//����Ǹ��ڵ�,֪ͨ״̬��
	if (AnimName==FString(TEXT("Default")))
	{
		CompiledState->AnimStateMachine->RootState = CompiledState;
	}
}

void UCreatureAnimStateNode::InitNode(class UCreatureAnimStateMachine* stateMachine)
{
	CompiledState = NewObject<UCreatureAnimState>(stateMachine->GetOuter());
	CompiledState->AnimStateMachine = stateMachine;
}

FLinearColor UCreatureAnimStateNode::GetNodeTitleColor() const
{
	if (CompiledState==nullptr)
	{
		return FLinearColor::Gray;
	}
	if (CompiledState->bIsCurrentState)
	{
		return FLinearColor::Yellow;
	}
	else
		return FLinearColor::Gray;
}




