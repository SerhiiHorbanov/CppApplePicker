// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Apple.generated.h"

UCLASS()
class CPPAPPLEPICKER_API AApple : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(EditAnywhere, Category="Apple")
	float MinZ;
	
	UPROPERTY(EditAnywhere, Category="Apple", Instanced)
	USceneComponent* Sphere;
	
	bool AlreadyHit = false;
	
	AApple();

	virtual void Tick(float DeltaTime) override;
};
