#include "CreatureEditorPCH.h"
#include "CreatureAnimationAssetFactory.h"
#include "CreatureAnimationAsset.h"
#define LOCTEXT_NAMESPACE "CreatureAnimationAssetFactory"
UCreatureAnimationAssetFactory::UCreatureAnimationAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UCreatureAnimationAsset::StaticClass();
}
UObject* UCreatureAnimationAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UCreatureAnimationAsset>(InParent, Class, Name, Flags);
}
#undef LOCTEXT_NAMESPACE