
#include "CreatureEditorPCH.h"
#include "AssetEditorModeManager.h"
#include "CreatureAnimStoreEditorViewportClient.h"
FCreatureAnimStoreEditorViewportClient::FCreatureAnimStoreEditorViewportClient(const TWeakPtr<class SEditorViewport>& InEditorViewportWidget /*= nullptr*/)
	:FEditorViewportClient(new FAssetEditorModeManager(), nullptr, InEditorViewportWidget)
{

}

void FCreatureAnimStoreEditorViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);
}

FLinearColor FCreatureAnimStoreEditorViewportClient::GetBackgroundColor() const
{
	return FLinearColor::Black;
}

void FCreatureAnimStoreEditorViewportClient::AddReferencedObjects(FReferenceCollector& Collector)
{
	
}


