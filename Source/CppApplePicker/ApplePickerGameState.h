// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ApplePickerGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScoreChanged, int, NewValue);

UCLASS()
class CPPAPPLEPICKER_API AApplePickerGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category="ApplePickerGameState")
	int Score;

	UPROPERTY(BlueprintReadOnly, Category="ApplePickerGameState")
	int HighScore;
	
	UPROPERTY(BlueprintAssignable, Category="ApplePickerGameState")
	FScoreChanged OnScoreChanged;
	
	void LoadHighScore();
	
	virtual void BeginPlay() override;
	void SaveHighScore();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	void IncreaseScore();
};
