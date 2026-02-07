// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameState.h"

#include "HighScoreSave.h"
#include "Kismet/GameplayStatics.h"

void AApplePickerGameState::LoadHighScore()
{
	const UHighScoreSave* Save = Cast<UHighScoreSave>(
		UGameplayStatics::LoadGameFromSlot(TEXT("HighScore"), 0)
	);

	if (Save)
	{
		HighScore = Save->HighScore;
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("HighScore: %d"), HighScore));
}

void AApplePickerGameState::BeginPlay()
{
	Super::BeginPlay();

	LoadHighScore();
}

void AApplePickerGameState::SaveHighScore()
{
	UHighScoreSave* Save = Cast<UHighScoreSave>(
		UGameplayStatics::CreateSaveGameObject(UHighScoreSave::StaticClass())
	);

	Save->HighScore = Score;

	UGameplayStatics::SaveGameToSlot(Save, TEXT("HighScore"), 0);
}

void AApplePickerGameState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("HighScore on end: %d"), HighScore));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Score on end: %d"), Score));
	
	if (Score > HighScore)
		SaveHighScore();
}

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
