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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basket")
	int InitialBasketsAmount = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basket")
	UClass* SingleBasketClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Basket")
	FVector OffsetPerBasket = FVector(0, 0, 75);
	
	UPROPERTY()
	TArray<USceneComponent*> Baskets;
	
public:
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void OnHit(AActor* Other);

	void RemoveBasket();
	
	bool NoBasketsLeft() const;
	
	void MoveTo(const FVector& NewPos);
};
