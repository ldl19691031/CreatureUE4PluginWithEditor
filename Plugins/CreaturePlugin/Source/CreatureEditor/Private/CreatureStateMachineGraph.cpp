#include "CreatureEditorPCH.h"
#include "CreatureStateMachineGraph.h"
#include "EdGraph/EdGraphSchema.h"
#include "CreatureAnimGraphSchema.h"
UCreatureStateMachineGraph::UCreatureStateMachineGraph(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Schema = UCreatureAnimGraphSchema::StaticClass();
}
