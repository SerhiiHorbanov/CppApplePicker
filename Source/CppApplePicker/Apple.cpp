// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"

AApple::AApple()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AApple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float z = Sphere->GetComponentLocation().Z;
	
	if (z < MinZ)
	{
		Destroy();
		GEngine->AddOnScreenDebugMessage(
			-1,
			2.0f,
			FColor::Green,
			TEXT("Method is running")
		);
	}
}

