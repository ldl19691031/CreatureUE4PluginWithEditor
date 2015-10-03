/********************************************************************************
** auth�� God Of Pen
** desc�� ����2d��Ϸ��Character��������ٿ�����Ҫ��ԭ�͡���Ҳ���Խ����Լ���Character
** Ver.:  V1.0.0
*********************************************************************************/

#include "Engine.h"
#include "CreatureMeshComponent.h"
#include "CreatureCharacter.generated.h"
UCLASS()
class ACreatureCharacter :public ACharacter{
	GENERATED_UCLASS_BODY()
public:
	UCreatureMeshComponent* GetCreatureMesh();
public:
	UPROPERTY(Category = Character, EditAnywhere, BlueprintReadWrite)
		//Use This to Mirror your Character's direction
		bool FlipCreatureMesh=false;
	
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
		//Use Check Is your Character is mirroring
		bool IsMirror=false;

	virtual void Tick(float DeltaTimes) override;

private:
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCreatureMeshComponent* CreatureMesh;

	void MirrorCreatureMesh();

};