// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameMode.h"

void AApplePickerGameMode::OnAppleDied()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor(255,1,1), TEXT("apl dropd"));
	
	UWorld* World = GetWorld();
	
	APlayerController* FirstPlayerController = World->GetFirstPlayerController();
	
	if (!FirstPlayerController)
		return;
	
	APawn* Pawn = FirstPlayerController->GetPawn();
	
	if (!Pawn)
		return;
	
	ABasket* Basket = Cast<ABasket>(Pawn);
	
	if (!Basket)
		return;
	
	Basket->RemoveBasket();
	if (!Basket->NoBasketsLeft())
		return;
	
	World->ServerTravel(TEXT("?restart"), false);
}
