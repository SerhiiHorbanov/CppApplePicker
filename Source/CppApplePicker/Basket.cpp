// Fill out your copyright notice in the Description page of Project Settings.

#include "Basket.h"

void ABasket::OnHit(AActor* Other)
{
	if (Other->ActorHasTag("Apple"))
	{
		Other->Destroy();
	}
}

void ABasket::MoveTo(const FVector& NewPos)
{
	SetActorLocation(NewPos);
}
