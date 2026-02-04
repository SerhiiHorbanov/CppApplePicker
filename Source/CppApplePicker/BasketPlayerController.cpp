// Fill out your copyright notice in the Description page of Project Settings.


#include "BasketPlayerController.h"

#include "Basket.h"

void ABasketPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ABasket* PossessedBasket = Cast<ABasket>(GetPawn());

	if (!PossessedBasket) 
		return;
	
	FVector MousePos;
	FVector ScreenPos;
	
	DeprojectMousePositionToWorld(MousePos, ScreenPos);
	PossessedBasket->MoveTo(MousePos);
}
