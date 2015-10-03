/********************************************************************************
** auth： God Of Pen
** desc： 用于2d游戏的Character，方便快速开发需要的原型。您也可以建立自己的Character
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