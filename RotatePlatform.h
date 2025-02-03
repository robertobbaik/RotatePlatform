// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatePlatfrom.generated.h"

UENUM()
enum class ERotateState
{
	ROLL UMETA(DisplayName = "Roll"),
	PITCH UMETA(DisplayName = "Pitch"),
	YAW UMETA(DisplayName = "Yaw")
};

UCLASS()
class SPARTAPROJECT_API ARotatePlatfrom : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotatePlatfrom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ComplexPlatform|Properties")
	ERotateState ERotate_State;

	UPROPERTY(EditAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ComplexPlatform|Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ComplexPlatform|Properties")
	float RotateSpeed;
	
	float Temp = 0;

	void ChangeDirection();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ComplexPlatform|Properties")
	float WaitTime = 0;
};

