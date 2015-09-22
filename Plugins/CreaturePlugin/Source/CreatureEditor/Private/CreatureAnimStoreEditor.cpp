#include "CreatureEditorPCH.h"
#include "CreatureAnimStoreEditor.h"
#include "CreatureAnimStateMachine.h"
#include "CreatureStateMachineGraph.h"
#include "SDockTab.h"
#include "GraphEditorActions.h"
#include "GraphEditor.h"
#include "IToolkitHost.h"
#include "GenericCommands.h"
#include "CreatureAnimTransitionNode.h"
#include "SEditorViewport.h"
#include "SCreatureAnimClipStoreEditorViewport.h"
#define LOCTEXT_NAMESPACE "AssetTypeEditors"

void FCreatureAnimStoreEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(TabManager);
	//注册细节面板
	TabManager->RegisterTabSpawner(FName(TEXT("Details")), FOnSpawnTab::CreateLambda(
		[&](const FSpawnTabArgs& Args){
		TSharedPtr<FCreatureAnimStoreEditor> StoreEditorPtr = SharedThis(this);// Spawn the tab
		return SNew(SDockTab)
			.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
			.Label(LOCTEXT("DetailsTab_Title", "Details"))
			[
				SNew(SStoreDetailPanel, StoreEditorPtr)

			];}
		))
		.SetDisplayName(LOCTEXT("DetailsTabLabel", "Details"))
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

//注册Viewport
TabManager->RegisterTabSpawner(FName(TEXT("Preview")), FOnSpawnTab::CreateLambda(
		[&](const FSpawnTabArgs& Args){
		TSharedPtr<FCreatureAnimStoreEditor> StoreEditorPtr = SharedThis(this);// Spawn the tab
		return SNew(SDockTab)
			.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
			.Label(LOCTEXT("Preview_Title", "Preview"))
			[
				SNew(SCreatureAnimClipStoreEditorViewport)

			];}
		))
		.SetDisplayName(LOCTEXT("DetailsTabLabel", "Details"))
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}
void FCreatureAnimStoreEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(TabManager);

}
FName FCreatureAnimStoreEditor::GetToolkitFName() const
{
	return FName("AnimStoreEditor");
}

FText FCreatureAnimStoreEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AnimStoreEditorAppLabelBase", "Anim Store Editor");
}

FText FCreatureAnimStoreEditor::GetToolkitName() const
{
	return FText::FromString(EditClipsStore->GetName());
}

FText FCreatureAnimStoreEditor::GetToolkitToolTipText() const
{
	return GetToolTipTextForObject(EditClipsStore);
}

FString FCreatureAnimStoreEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("Anim Store Editor");
}

FString FCreatureAnimStoreEditor::GetDocumentationLink() const
{
	return TEXT("Engine/Paper2D/TileMapEditor");
}

void FCreatureAnimStoreEditor::OnToolkitHostingStarted(const TSharedRef< class IToolkit >& Toolkit)
{
	
}

void FCreatureAnimStoreEditor::OnToolkitHostingFinished(const TSharedRef< class IToolkit >& Toolkit)
{
	

}

FLinearColor FCreatureAnimStoreEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}
void FCreatureAnimStoreEditor::InitAnimStoreEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UCreatureAnimationClipsStore* Store){
	EditClipsStore = Store;

	// 定义了编辑器面板的默认显示样式
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_ClipStoreEditor_Layout")
		->AddArea
		(
		FTabManager::NewPrimaryArea()
		->SetOrientation(Orient_Vertical)
		->Split
		(
		FTabManager::NewStack()
		->SetSizeCoefficient(0.1f)
		->SetHideTabWell(true)
		->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
		)
		->Split
		(
		FTabManager::NewSplitter()
		->SetOrientation(Orient_Horizontal)
		->SetSizeCoefficient(0.9f)
		->Split
		(
			FTabManager::NewSplitter()
			->SetOrientation(Orient_Vertical)
			->Split(
			FTabManager::NewStack()
			->SetHideTabWell(true)
			->AddTab(FName(TEXT("Preview")), ETabState::OpenedTab)
			)
			->Split(
			FTabManager::NewStack()
			->SetHideTabWell(true)
			->AddTab(FName(TEXT("Details")), ETabState::OpenedTab)
			)
		)
		->Split
		(
		FTabManager::NewStack()
		->SetSizeCoefficient(0.8f)
		->SetHideTabWell(true)
		->AddTab(FName(TEXT("BluePrint")), ETabState::OpenedTab)
		)


		)



		);

	// Initialize the asset editor and spawn the layout above
	InitAssetEditor(Mode, InitToolkitHost, FName(TEXT("StateMachineEditorApp")), StandaloneDefaultLayout, /*bCreateDefaultStandaloneMenu=*/ true, /*bCreateDefaultToolbar=*/ true, Store);
}




#undef LOCTEXT_NAMESPACE  