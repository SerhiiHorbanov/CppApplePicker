// Fill out your copyright notice in the Description page of Project Settings.

#include "Basket.h"

#include "ApplePickerGameState.h"

void ABasket::OnHit(AActor* Other)
{
	if (Other->ActorHasTag("Apple"))
	{
		Other->Destroy();
		
		AApplePickerGameState* GameState = GetWorld()->GetGameState<AApplePickerGameState>();
		if (GameState)
			GameState->IncreaseScore();
	}
}

void ABasket::MoveTo(const FVector& NewPos)
{
	SetActorLocation(NewPos);
}
