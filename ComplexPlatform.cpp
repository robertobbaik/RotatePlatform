// Fill out your copyright notice in the Description page of Project Settings.


#include "ComplexPlatform.h"

// Sets default values
AComplexPlatform::AComplexPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AComplexPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComplexPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Temp += DeltaTime;

	float MoveDir = IsLeft ? -1 * MoveSpeed * DeltaTime * FMath::Sin(Temp) : MoveSpeed * DeltaTime * FMath::Sin(Temp);
	AddActorLocalOffset(FVector(0,MoveDir,0));
}

