#include "CustomProceduralMesh.h"
#include "CreatureStateMachineGraph.h"
#include "EdGraph/EdGraphSchema.h"
#include "Editor/AnimGraph/Classes/AnimationStateMachineSchema.h"
UCreatureStateMachineGraph::UCreatureStateMachineGraph(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Schema = UAnimationStateMachineSchema::StaticClass();
}
