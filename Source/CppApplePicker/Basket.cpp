// Fill out your copyright notice in the Description page of Project Settings.

#include "Basket.h"

ABasket::ABasket()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(
		TEXT("/Engine/BasicShapes/Cube.Cube")
	);

	if (Cube.Succeeded())
	{
		CubeMesh->SetStaticMesh(Cube.Object);
	}
}
