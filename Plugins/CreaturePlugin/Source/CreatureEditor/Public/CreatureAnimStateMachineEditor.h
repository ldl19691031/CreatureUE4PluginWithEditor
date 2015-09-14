#include "Toolkits/AssetEditorToolkit.h"
#include "Editor/KismetWidgets/Public/SSingleObjectDetailsPanel.h"
#include "CreatureAnimStateMachine.h"


//����ฺ����༭�������
#pragma once
class FCreatureAnimStateMachineEditor :public FAssetEditorToolkit{
public:
	//IToolKitInterface
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	//EndIToolKitInterface

	// FAssetEditorToolkit
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FString GetDocumentationLink() const override;
	virtual void OnToolkitHostingStarted(const TSharedRef< class IToolkit >& Toolkit) override;
	virtual void OnToolkitHostingFinished(const TSharedRef< class IToolkit >& Toolkit) override;
	// End of FAssetEditorToolkit
	void InitAnimStateMachineEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UCreatureAnimStateMachine* StateMachine);
	
	UCreatureAnimStateMachine* GetEditingStateMachine();
private:
	UCreatureAnimStateMachine* EditingStateMachine;

};
//Detail�༭��
class SCreatureAnimStateMachinePropertiesTabBody : public SSingleObjectDetailsPanel
{
public:
	SLATE_BEGIN_ARGS(SCreatureAnimStateMachinePropertiesTabBody) {}
	SLATE_END_ARGS()

private:
	// Pointer back to owning TileMap editor instance (the keeper of state)
	TWeakPtr<FCreatureAnimStateMachineEditor> EditorPtr;
public:
	void Construct(const FArguments& InArgs, TSharedPtr<FCreatureAnimStateMachineEditor> Editor)
	{
		EditorPtr = Editor;

		SSingleObjectDetailsPanel::Construct(SSingleObjectDetailsPanel::FArguments().HostCommandList(Editor->GetToolkitCommands()), /*bAutoObserve=*/ true, /*bAllowSearch=*/ true);
	}

	// SSingleObjectDetailsPanel interface
	virtual UObject* GetObjectToObserve() const override
	{
		return EditorPtr.Pin()->GetEditingStateMachine();
	}

	virtual TSharedRef<SWidget> PopulateSlot(TSharedRef<SWidget> PropertyEditorWidget) override
	{
		return SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.FillHeight(1)
			[
				PropertyEditorWidget
			];
	}
	// End of SSingleObjectDetailsPanel interface
};