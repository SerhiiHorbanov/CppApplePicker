// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"

#include "ApplePickerGameMode.h"

AApple::AApple()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere = Mesh;
	
	Sphere->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere")
	);

	if (SphereMesh.Succeeded())
	{
		Mesh->SetStaticMesh(SphereMesh.Object);
	}
}

void AApple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!Sphere)
		return;

	const float Z = Sphere->GetComponentLocation().Z;
	
	FString str = FString::Printf(TEXT("Z: %f"), Z);
	
	if (Z < MinZ)
	{
		Destroy();
		AApplePickerGameMode* gameMode = GetWorld()->GetAuthGameMode<AApplePickerGameMode>();
		
		if (gameMode)
			gameMode->OnAppleDied();
	}
}

