/********************************************************************************
** auth�� God Of Pen
** desc�� ��δ��д����
** Ver.:  V1.0.0
*********************************************************************************/

#include "Engine.h"
#include "CreatureTransitionCondition.h"
#include "CreatureAnimTransition.generated.h"
class UCreatureAnimState;
class UCreatureAnimStateMachine;
#pragma once




UCLASS(Blueprinttype)
class CREATUREPLUGIN_API UCreatureAnimTransition :public UObject{
	GENERATED_BODY()
public:
	//���ڻ�ȡת�������б�
	UPROPERTY()
	UCreatureAnimStateMachine* AnimStateMachine;

		//ת�������б�
		UPROPERTY()
			TArray<FCreatureTransitionCondition> TransitionConditions;

		UPROPERTY()
		UCreatureAnimState* TargetState;

		bool Translate();
		//Special Translate, Using when animation end
		void AnimationEndTranslate();
};