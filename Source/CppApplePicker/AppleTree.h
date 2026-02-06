// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleTree.generated.h"

UCLASS()
class CPPAPPLEPICKER_API AAppleTree : public AActor
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, Category="AppleTree")
	UClass* AppleClass;	
	
	UPROPERTY(EditAnywhere, Category="AppleTree")
	float Speed;
	
	UPROPERTY(EditAnywhere, Category="AppleTree")
	float RightAndLeftEdge;
	
	UPROPERTY(EditAnywhere, Category="AppleTree")
	float ChanceToChangeDirection;
	
	UPROPERTY(EditAnywhere, Category="AppleTree")
	float ChangeDirectionAttemptInterval;
	
	UPROPERTY(EditAnywhere, Category="AppleTree")
	float SecondsBetweenAppleDrops;
	
	AAppleTree();

protected:
	
	virtual void BeginPlay() override;
	
public:	
	
	void DropApple() const;
	void TryChangeDirectionRandomly();
	
	virtual void Tick(float DeltaTime) override;
};
