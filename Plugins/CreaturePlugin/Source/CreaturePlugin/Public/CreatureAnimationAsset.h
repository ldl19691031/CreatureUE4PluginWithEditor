/********************************************************************************
** auth�� God Of Pen
** desc�� �洢���������ļ����������ж���
** Ver.:  V1.0.0
*********************************************************************************/
#pragma  once
#include "Engine.h"
#include "CreatureAnimationAsset.generated.h"


UCLASS()
class CREATUREPLUGIN_API UCreatureAnimationAsset :public UObject{
	GENERATED_BODY()
public:
		//Ϊ�����¼��ݣ���������ʹ�ã�
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Creature")
		FString creature_filename;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Creature")
		TArray<FString> AnimationClipList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature")
		float animation_speed=1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature")
		UMaterialInterface * collection_material;
	//���ļ��ж�ȡ����JSon Data
	UPROPERTY()
		FString CreatureFileJSonData;


};