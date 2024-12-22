// Fill out your copyright notice in the Description page of Project Settings.

#include "GameSpawner.h"

void AGameSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnPlayer();
	SpawnGems();
}

void AGameSpawner::SpawnPlayer()
{
	GetWorld()->SpawnActor<AActor>(Player, InitialPosition);
}

void AGameSpawner::SpawnGems()
{
	Gems = FMath::RandRange(MinGemsAmount, MaxGemsAmount);

	for (int i = 0; i < Gems; i++)
	{
		float XPos = FMath::RandRange(0, Width) * DistanceBetweenPositions;
		float YPos = FMath::RandRange(0, Length) * DistanceBetweenPositions;

		FTransform GemSpawnTransform = FTransform(FVector(XPos, YPos, 0));
		GemSpawnTransform += InitialPosition;
		
		GetWorld()->SpawnActor<AActor>(Gem, GemSpawnTransform);
	}
}

void AGameSpawner::SpawnFruit()
{
	float XPos = static_cast<float>(Width) / 2 * DistanceBetweenPositions;
	float YPos = static_cast<float>(Length) / 2 * DistanceBetweenPositions;

	FTransform FruitSpawnTransform = FTransform(FVector(XPos, YPos, 0));
	FruitSpawnTransform += InitialPosition;
		
	GetWorld()->SpawnActor<AActor>(Fruit, FruitSpawnTransform);
}

void AGameSpawner::DecreaseGems(int amount)
{
	Gems -= amount;
	if (Gems <= 0) {
		SpawnFruit();
	}
}
