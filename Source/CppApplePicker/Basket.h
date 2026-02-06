// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Basket.generated.h"

UCLASS()
class CPPAPPLEPICKER_API ABasket : public APawn
{
	GENERATED_BODY()
	
protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* CubeMesh;
	
public:
	
	UFUNCTION(BlueprintCallable)
	void OnHit(AActor* Other);

	void MoveTo(const FVector& NewPos);
};
