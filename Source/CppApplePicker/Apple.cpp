// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"

AApple::AApple()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	Sphere = Mesh;
	Sphere->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(
		TEXT("/Engine/BasicShapes/Sphere.Sphere")
	);

	if (Cube.Succeeded())
	{
		Mesh->SetStaticMesh(Cube.Object);
	}
}

void AApple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!Sphere)
		return;

	const float Z = Sphere->GetComponentLocation().Z;
	
	if (Z < MinZ)
	{
		Destroy();
	}
}

