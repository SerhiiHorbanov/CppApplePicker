// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "HighScoreSave.generated.h"

UCLASS()
class CPPAPPLEPICKER_API UHighScoreSave : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	int HighScore = 0;
};
