#pragma once
#include "Engine.h"
#include "AnimationRuntime.h"
#include "EdGraph/EdGraph.h"
#include "Editor/AnimGraph/Classes/AnimationStateMachineGraph.h"
#include "CreatureAnimStateMachine.generated.h"

UCLASS(Blueprintable)
class CREATUREPLUGIN_API UCreatureAnimStateMachine :
	public UObject
{
	GENERATED_BODY()
		UCreatureAnimStateMachine();
public:
	UPROPERTY(EditAnywhere, Category = "CreatureAnimStateMachine")
		FString Name;

	UPROPERTY()
	UAnimationStateMachineGraph* StateMachineGraph;
};

