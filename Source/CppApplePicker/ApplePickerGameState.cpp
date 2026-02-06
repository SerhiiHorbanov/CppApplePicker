// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameState.h"

void AApplePickerGameState::IncreaseScore()
{
	Score += 100;
	FString ScoreString = FString::FromInt(Score);
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.0f,
		FColor::Green,
		ScoreString	
		);
}
