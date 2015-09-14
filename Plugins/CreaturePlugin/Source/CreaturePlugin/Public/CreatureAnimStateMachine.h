#pragma once
#include "Engine.h"
#include "AnimationRuntime.h"
#include "EdGraph/EdGraph.h"
#include "CreatureStateMachineGraph.h"
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
	UCreatureStateMachineGraph* StateMachineGraph;
};

