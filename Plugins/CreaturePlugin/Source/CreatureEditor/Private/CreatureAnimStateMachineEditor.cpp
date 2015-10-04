#include "CreatureEditorPCH.h"
#include "CreatureAnimStateMachineEditor.h"
#include "CreatureAnimStateMachine.h"
#include "CreatureStateMachineGraph.h"
#include "SDockTab.h"
#include "GraphEditorActions.h"
#include "GraphEditor.h"
#include "IToolkitHost.h"
#include "GenericCommands.h"
#include "CreatureAnimTransitionNode.h"

#define LOCTEXT_NAMESPACE "AnimAssetEditors"

void FCreatureAnimStateMachineEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
	GraphEditorCommands = MakeShareable(new FUICommandList());
	FAssetEditorToolkit::RegisterTabSpawners(TabManager);

	
	//��ͼ�༭�������
	GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
		FExecuteAction::CreateSP(this,&FCreatureAnimStateMachineEditor::OnDeleteNode)
		);

	/*NodeAction.OnSelectionChanged.BindLambda(
		[&](const FGraphPanelSelectionSet& selection){
				for (auto obj : selection)
				{
					if (UCreatureAnimStateNode* Node =Cast<UCreatureAnimStateNode>(obj))
					{
						EditGraph->NotifyGraphChanged();
					}
				}
			}
	);*/
	EditGraph =SNew(SGraphEditor)
		.GraphToEdit(EditingStateMachine->StateMachineGraph)
		.IsEditable(true)
		.AdditionalCommands(GraphEditorCommands)
		.GraphEvents(NodeAction)
		;
	//��ϸ��������������
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
			//���ڲ������ֵ�Lambda���ʽ
			[&](const FSpawnTabArgs& Args){
			return SNew(SDockTab)
				.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
				.Label(LOCTEXT("BlueprintTab_Title", "Blueprint"))
				[
					EditGraph.ToSharedRef()//Slate�����ṩһ��sharedRef������Ҫԭ�ع����ؼ�
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
	
	// �����˱༭������Ĭ����ʾ��ʽ
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
					->SetSizeCoefficient(0.1f)
					->SetHideTabWell(true)
					->AddTab(FName(TEXT("Details")), ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.1f)
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

void FCreatureAnimStateMachineEditor::OnDeleteNode()
{
	if (EditGraph.IsValid())
	{
		for (auto node:EditGraph->GetSelectedNodes())
		{
			if (UEdGraphNode* GraphNode=Cast<UEdGraphNode>(node))
			{
				GraphNode->DestroyNode();
			}
		}
	}
}

UEdGraphNode* FCreatureAnimStateMachineEditor::GetSelectNode()
{
	if (EditGraph.IsValid() && EditGraph->GetSelectedNodes().Num()!=0)
	{
		auto Node = EditGraph->GetSelectedNodes().Array()[0];
		if (Node!=nullptr)
		{
			return Cast<UEdGraphNode>(Node);
		}
		
		
	}
	return nullptr;

}

void FCreatureAnimStateMachineEditor::SaveAsset_Execute()
{
	Cast<UCreatureStateMachineGraph>(EditingStateMachine->StateMachineGraph)->CompileNodes();
	FAssetEditorToolkit::SaveAsset_Execute();
}

#undef LOCTEXT_NAMESPACE  