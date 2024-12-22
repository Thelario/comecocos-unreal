// Fill out your copyright notice in the Description page of Project Settings.

#include "CeldaComponent.h"

// Sets default values for this component's properties
UCeldaComponent::UCeldaComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UCeldaComponent::BeginPlay()
{
	Super::BeginPlay();
	
	auto *pawn = GetWorld()->
	GetFirstPlayerController()->
	GetPawn();

	// puede devolver `nullptr` si el casting falla
	_adventurer = Cast<ACPPAdventurer>(pawn); 
}

// Called every frame
void UCeldaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}