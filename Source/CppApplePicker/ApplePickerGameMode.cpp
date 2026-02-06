// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplePickerGameMode.h"

void AApplePickerGameMode::OnAppleDied() const
{
	GetWorld()->ServerTravel(TEXT("?restart"), false);
}
