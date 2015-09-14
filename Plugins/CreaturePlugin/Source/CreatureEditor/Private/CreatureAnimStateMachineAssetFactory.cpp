#include "CreatureEditorPCH.h"
#include "CreatureAnimStateMachineAssetFactory.h"
#define LOCTEXT_NAMESPACE "CreatureAnimStateMachineAssetFactory"
UCreatureAnimStateMachineAssetFactory::UCreatureAnimStateMachineAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UCreatureAnimStateMachine::StaticClass();
}

UObject* UCreatureAnimStateMachineAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UCreatureAnimStateMachine * StateMachineAsset = NewObject<UCreatureAnimStateMachine>(InParent, Class, Name, Flags);
	return StateMachineAsset;
}
#undef LOCTEXT_NAMESPACE