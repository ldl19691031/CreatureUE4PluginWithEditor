#include "CreatureEditorPCH.h"
#include "CreatureAnimStateMachineEditor.h"
#include "CreatureAnimStateMachine.h"
#include "SDockTab.h"
#include "GraphEditorActions.h"
#include "GraphEditor.h"
#include "IToolkitHost.h"
#define LOCTEXT_NAMESPACE "AssetTypeEditors"
void FCreatureAnimStateMachineEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(TabManager);

	//TabManager->RegisterTabSpawner(FTileMapEditorTabs::ViewportID, FOnSpawnTab::CreateSP(this, &FTileMapEditor::SpawnTab_Viewport))
	//	.SetDisplayName(LOCTEXT("ViewportTab", "Viewport"))
	//	.SetGroup(WorkspaceMenuCategoryRef)
	//	.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));

	//将细节面板放入左侧面板
	TabManager->RegisterTabSpawner(FName(TEXT("Details")), FOnSpawnTab::CreateLambda(
		[&](const FSpawnTabArgs& Args){
		TSharedPtr<FCreatureAnimStateMachineEditor> StateMechineEditorPtr = SharedThis(this);

			// Spawn the tab
			return SNew(SDockTab)
				.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
				.Label(LOCTEXT("DetailsTab_Title", "Details"))
				[
					SNew(SCreatureAnimStateMachinePropertiesTabBody,StateMechineEditorPtr)

				];
			}
		))
		.SetDisplayName(LOCTEXT("DetailsTabLabel", "Details"))
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

			TabManager->RegisterTabSpawner(FName(TEXT("BluePrint")), FOnSpawnTab::CreateLambda(
				[&](const FSpawnTabArgs& Args){
				return SNew(SDockTab)
					.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
					.Label(LOCTEXT("BlueprintTab_Title", "Blueprint"))
					[
						SNew(SGraphEditor)
						.GraphToEdit(EditingStateMachine->StateMachineGraph)

					];

				}
				))
					.SetDisplayName(LOCTEXT("DetailsTabLabel", "Details"))
					.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}
void FCreatureAnimStateMachineEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(TabManager);

}
FName FCreatureAnimStateMachineEditor::GetToolkitFName() const
{
	return FName("TileMapEditor");
}

FText FCreatureAnimStateMachineEditor::GetBaseToolkitName() const
{
	return LOCTEXT("TileMapEditorAppLabelBase", "Tile Map Editor");
}

FText FCreatureAnimStateMachineEditor::GetToolkitName() const
{
	return FText::FromString(EditingStateMachine->GetName());
}

FText FCreatureAnimStateMachineEditor::GetToolkitToolTipText() const
{
	return GetToolTipTextForObject(EditingStateMachine);
}

FString FCreatureAnimStateMachineEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("StateMachineEditor");
}

FString FCreatureAnimStateMachineEditor::GetDocumentationLink() const
{
	return TEXT("Engine/Paper2D/TileMapEditor");
}

void FCreatureAnimStateMachineEditor::OnToolkitHostingStarted(const TSharedRef< class IToolkit >& Toolkit)
{
	
}

void FCreatureAnimStateMachineEditor::OnToolkitHostingFinished(const TSharedRef< class IToolkit >& Toolkit)
{
	

}

FLinearColor FCreatureAnimStateMachineEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}
void FCreatureAnimStateMachineEditor::InitAnimStateMachineEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UCreatureAnimStateMachine* StateMachine){
	
	EditingStateMachine = StateMachine;
	// 定义了编辑器面板的默认显示样式
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_StateMachineEditor_Layout")
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
					FTabManager::NewStack()
					->SetSizeCoefficient(0.3f)
					->SetHideTabWell(true)
					->AddTab(FName(TEXT("Details")), ETabState::OpenedTab)
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
	InitAssetEditor(Mode, InitToolkitHost, FName(TEXT("StateMachineEditorApp")), StandaloneDefaultLayout, /*bCreateDefaultStandaloneMenu=*/ true, /*bCreateDefaultToolbar=*/ true, StateMachine);

}
UCreatureAnimStateMachine* FCreatureAnimStateMachineEditor::GetEditingStateMachine(){
	return EditingStateMachine;

}
#undef LOCTEXT_NAMESPACE  