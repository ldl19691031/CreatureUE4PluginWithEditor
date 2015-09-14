/********************************************************************************
** auth£º God Of Pen
** desc£º ¶¯»­×´Ì¬½Úµã
** Ver.:  V1.0.0
*********************************************************************************/
#include "Engine.h"
#include "EdGraph/EdGraphNode.h"
#include "CreatureAnimStateNode.generated.h"
#pragma  once
UCLASS()
class UCreatureAnimStateNode :public UEdGraphNode{
	GENERATED_BODY()
public:
	UPROPERTY()
	TArray<UEdGraphPin*> InputPins;
	UPROPERTY()
	TArray<UEdGraphPin*> OutputPins;

public:
	UCreatureAnimStateNode()
		:UEdGraphNode()
	{
		NodeHeight = 50;
	

	}
	virtual TSharedPtr<SGraphNode> CreateVisualWidget() { return TSharedPtr<SGraphNode>(); }
	virtual void OnRenameNode(const FString& NewName)override;
	virtual bool CanUserDeleteNode() const override;

};
