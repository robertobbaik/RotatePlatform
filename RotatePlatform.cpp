// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatePlatfrom.h"

// Sets default values
ARotatePlatfrom::ARotatePlatfrom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ARotatePlatfrom::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ARotatePlatfrom::ChangeDirection, WaitTime, true);
}

// Called every frame
void ARotatePlatfrom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Temp += DeltaTime;

	FRotator Rotator = FRotator();

	switch (ERotate_State)
	{
	case ERotateState::ROLL:
		Rotator = FRotator(0, 0, 1);
		break;
	case ERotateState::PITCH:
		Rotator = FRotator(1, 0, 0);
		break;
	case ERotateState::YAW:
		Rotator = FRotator(0, 1, 0);
		break;
	}

	AddActorLocalRotation(Rotator * DeltaTime * RotateSpeed);
}

void ARotatePlatfrom::ChangeDirection()
{
	UE_LOG(LogTemp, Display, TEXT("Rotate Platfrom Test"));
	RotateSpeed *= -1;
}

