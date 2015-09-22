#include "CreatureEditorPCH.h"
#include "EditorViewportClient.h"
#include "SCreatureAnimClipStoreEditorViewport.h"
#include "CreatureAnimStoreEditorViewportClient.h"
#define LOCTEXT_NAMESPACE "CreatureAnimClipStoreEditorViewport"
void SCreatureAnimClipStoreEditorViewport::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SEditorViewport::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
}

FReply SCreatureAnimClipStoreEditorViewport::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FReply SCreatureAnimClipStoreEditorViewport::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FReply SCreatureAnimClipStoreEditorViewport::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FReply SCreatureAnimClipStoreEditorViewport::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

FCursorReply SCreatureAnimClipStoreEditorViewport::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	return FCursorReply::Unhandled();
}

int32 SCreatureAnimClipStoreEditorViewport::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	return 0;
}

void SCreatureAnimClipStoreEditorViewport::Construct(const FArguments& InArgs)
{
	SEditorViewport::Construct(SEditorViewport::FArguments());
}

TSharedRef<FEditorViewportClient> SCreatureAnimClipStoreEditorViewport::MakeEditorViewportClient()
{
	TSharedPtr<FEditorViewportClient> TargetClient(new FCreatureAnimStoreEditorViewportClient());
	return TargetClient.ToSharedRef();
}

FText SCreatureAnimClipStoreEditorViewport::GetTitleText() const
{
	return LOCTEXT("TitleTEXT","ClipStorePreview");
}
#undef LOCTEXT_NAMESPACE