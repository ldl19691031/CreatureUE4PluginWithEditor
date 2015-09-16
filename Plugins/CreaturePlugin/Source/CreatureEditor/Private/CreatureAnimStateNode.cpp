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
	////没有出口状态，死循环？
	//if (Pins.Num()==0)
	//{
	return;
}
for (UEdGraphPin* Pin : Pins)
{
	if (Pin->Direction == EEdGraphPinDirection::EGPD_Output)
	{
		for (UEdGraphPin* TargetPin : Pin->LinkedTo)
		{
			UCreatureAnimTransitionNode* TargetNode = TargetPin->GetOwningNode();

		}
	}

}
}

void UCreatureAnimStateNode::InitNode(class UCreatureAnimStateMachine* stateMachine)
{
	CompiledState = NewObject<UCreatureAnimState>(stateMachine->GetOuter());
	CompiledState->AnimStateMachine = stateMachine;
}




