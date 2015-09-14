// Fill out your copyright notice in the Description page of Project Settings.

#include "brs2d.h"
#include "BaseCharactor.h"


// Sets default values
ABaseCharactor::ABaseCharactor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharactor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharactor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseCharactor::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

