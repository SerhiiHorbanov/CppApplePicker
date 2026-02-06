// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleTree.h"

AAppleTree::AAppleTree()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AAppleTree::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerManager& TimerManager = GetWorldTimerManager();
	
	FTimerHandle DropAppleTimerHandle;
	TimerManager.SetTimer(DropAppleTimerHandle, this, &AAppleTree::DropApple, SecondsBetweenAppleDrops, true);

	FTimerHandle ChangeDirectionAttemptTimerHandle;
	TimerManager.SetTimer(ChangeDirectionAttemptTimerHandle, this, &AAppleTree::TryChangeDirectionRandomly, ChangeDirectionAttemptInterval, true);
}

void AAppleTree::DropApple() const
{
	const FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	
	GetWorld()->SpawnActor(AppleClass, &GetActorTransform(), SpawnParameters);
}

void AAppleTree::TryChangeDirectionRandomly()
{
	if (FMath::RandRange(0.0f, 1.0f) < ChanceToChangeDirection)
		Speed *= -1.0f;
}

void AAppleTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector Position = GetActorLocation();
	
	if (Position.Y > RightAndLeftEdge)
		Speed = -abs(Speed);
	else if (Position.Y < -RightAndLeftEdge)
		Speed = abs(Speed);
	
	Position.Y += Speed * DeltaTime;
	
	SetActorLocation(Position);
}

