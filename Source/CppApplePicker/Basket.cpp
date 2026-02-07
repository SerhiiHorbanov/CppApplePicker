// Fill out your copyright notice in the Description page of Project Settings.

#include "Basket.h"

#include "ApplePickerGameState.h"

void ABasket::BeginPlay()
{
	Super::BeginPlay();
	
	Baskets.Reserve(InitialBasketsAmount);
	for (int i = 0; i < InitialBasketsAmount; i++)
	{
		USceneComponent* BasketComponent = NewObject<USceneComponent>(this, SingleBasketClass);
		
		if (BasketComponent)
		{
			BasketComponent->RegisterComponent();
			BasketComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
			BasketComponent->SetRelativeLocation(OffsetPerBasket * i);
			
			Baskets.Add(BasketComponent);
		}
	}
}

void ABasket::OnHit(AActor* Other)
{
	if (!Other)
		return;
	if (!Other->ActorHasTag("Apple"))
		return;

	Other->Destroy();
	
	AApplePickerGameState* GameState = GetWorld()->GetGameState<AApplePickerGameState>();
	
	if (GameState)
		GameState->IncreaseScore();
}

void ABasket::RemoveBasket()
{
	if (Baskets.IsEmpty())
		return;
	
	USceneComponent* Last = Baskets.Last();
	
	if (!Last)
		return;
	
	Last->DestroyComponent();
	
	Baskets.Pop();
}

bool ABasket::NoBasketsLeft() const
{
	return Baskets.IsEmpty();
}

void ABasket::MoveTo(const FVector& NewPos)
{
	SetActorLocation(NewPos);
}
