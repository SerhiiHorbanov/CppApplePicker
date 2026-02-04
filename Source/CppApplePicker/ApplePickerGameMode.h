// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Basket.h"
#include "BasketPlayerController.h"
#include "GameFramework/GameModeBase.h"
#include "ApplePickerGameMode.generated.h"

UCLASS()
class CPPAPPLEPICKER_API AApplePickerGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AApplePickerGameMode()
	{
		PlayerControllerClass = ABasketPlayerController::StaticClass();
		DefaultPawnClass = ABasket::StaticClass();
	};
};
