// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSpawner.generated.h"

UCLASS()
class COMECOCOS_API AGameSpawner : public AActor
{
	GENERATED_BODY()

	int Gems = 0;

	UPROPERTY(EditAnywhere, Category="Spawner|Config")
	int Width;

	UPROPERTY(EditAnywhere, Category="Spawner|Config")
	int Length;
	
	UPROPERTY(EditAnywhere, Category="Spawner|Config")
	float DistanceBetweenPositions;

	UPROPERTY(EditAnywhere, Category="Spawner|Config", meta=(MakeEditWidget))
	FTransform InitialPosition;

	UPROPERTY(EditAnywhere, Category="Spawner|Player")
	TSubclassOf<AActor> Player;
	
	UPROPERTY(EditAnywhere, Category="Spawner|Gems")
	int MinGemsAmount;

	UPROPERTY(EditAnywhere, Category="Spawner|Gems")
	int MaxGemsAmount;

	UPROPERTY(EditAnywhere, Category="Spawner|Gems")
	TSubclassOf<AActor> Gem;

	UPROPERTY(EditAnywhere, Category="Spawner|Fruit")
	TSubclassOf<AActor> Fruit;
	
protected:
	virtual void BeginPlay() override;

private:
	void SpawnPlayer();
	void SpawnGems();
	void SpawnFruit();

public:
	void DecreaseGems(int amount);
};
