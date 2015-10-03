
#include "CustomProceduralMesh.h"
#include "CreatureCharacter.h"
//重载构造函数，关掉默认的SkeletalComponent
ACreatureCharacter::ACreatureCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	CreatureMesh = CreateDefaultSubobject<UCreatureMeshComponent>(FName(TEXT("CreatureMesh")));
	if (CreatureMesh)
	{
		//初始化
	}

}

UCreatureMeshComponent* ACreatureCharacter::GetCreatureMesh()
{
	return CreatureMesh;
}

void ACreatureCharacter::Tick(float DeltaTimes)
{
	Super::Tick(DeltaTimes);
	//Check Should we mirror our character's mesh
	{
		FVector CharacterForwardDirection = GetActorForwardVector();
		FVector CharacterVelocityDirection = GetVelocity();
		float Dot = FVector::DotProduct(CharacterForwardDirection,CharacterVelocityDirection);
		//Velocity Direction is the same as ForwardDirection,We should not mirror
		if (Dot>0.1f&&IsMirror == !FlipCreatureMesh)
		{
			MirrorCreatureMesh();
		}
		if (Dot<-0.1f&&IsMirror == FlipCreatureMesh)
		{
			MirrorCreatureMesh();
		}

	}
}

void ACreatureCharacter::MirrorCreatureMesh()
{
		FTransform LastTransform = CreatureMesh->GetRelativeTransform();
		LastTransform.Mirror(EAxis::Y, EAxis::X);
		FVector LastScale = LastTransform.GetScale3D();
		LastScale.Y *= -1;
		LastTransform.SetScale3D(LastScale);
		CreatureMesh->SetRelativeTransform(LastTransform);
		IsMirror = !IsMirror;
}
