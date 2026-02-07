// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Basket.h"
#include "BasketPlayerController.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "ApplePickerGameMode.generated.h"

UCLASS()
class CPPAPPLEPICKER_API AApplePickerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void OnAppleDied();
};
