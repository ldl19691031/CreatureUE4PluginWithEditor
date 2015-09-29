/********************************************************************************
** auth�� God Of Pen
** desc�� ����Ԥ��ClipStore��ViewportClient
** Ver.:  V1.0.0
*********************************************************************************/
#pragma  once
#include "Engine.h"
#include "EditorViewportClient.h"
#include "PreviewScene.h"
class FCreatureAnimStoreEditorViewportClient : public FEditorViewportClient
{
public:
	/** Constructor */
	explicit FCreatureAnimStoreEditorViewportClient(const TWeakPtr<class SEditorViewport>& InEditorViewportWidget = nullptr,class UCreatureAnimationClipsStore* EditingAnimStore=nullptr);
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

	virtual void Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI) override;

	void ChangePreviewAnimation(FString AnimationName);

	void ReConstructMesh();
private:
	//����Ԥ����Scene
	FPreviewScene OwnerScene;

	class UCreatureMeshComponent* EditingCreatureMesh;
	class UCreatureAnimationClipsStore* EditingStore;
private:
	void SetUpEditingCreatureMesh();
	void SetUpCamera();
};