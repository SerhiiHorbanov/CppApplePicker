// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ApplePickerGameState.generated.h"

UCLASS()
class CPPAPPLEPICKER_API AApplePickerGameState : public AGameStateBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="ApplePickerGameState")
	int Score;

	UPROPERTY(EditAnywhere, Category="ApplePickerGameState")
	int HighScore;
	
public:
	
	void LoadHighScore();
	
	virtual void BeginPlay() override;
	void SaveHighScore();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	void IncreaseScore();
};
