/********************************************************************************
** auth£∫ God Of Pen
** desc£∫ ”√”⁄‘§¿¿ClipStoreµƒViewportClient
** Ver.:  V1.0.0
*********************************************************************************/
#pragma  once
#include "Engine.h"
#include "EditorViewportClient.h"
class FCreatureAnimStoreEditorViewportClient : public FEditorViewportClient
{
public:
	/** Constructor */
	explicit FCreatureAnimStoreEditorViewportClient(const TWeakPtr<class SEditorViewport>& InEditorViewportWidget = nullptr);
	//~CreatureAnimStoreEditorViewportClient();

	// FViewportClient interface
	virtual void Tick(float DeltaSeconds) override;
	// End of FViewportClient interface

	// FEditorViewportClient interface
	virtual FLinearColor GetBackgroundColor() const override;
	// End of FEditorViewportClient interface

	// FSerializableObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	// End of FSerializableObject interface


};