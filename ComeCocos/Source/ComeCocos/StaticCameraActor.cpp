// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticCameraActor.h"

#include "Kismet/GameplayStatics.h"

void AStaticCameraActor::BeginPlay()
{
	Super::BeginPlay();

	// We first try to find the player controller in the world.
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerController::StaticClass(), FoundActors);

	// Inform if the player controller couldn't be found.
	
	if (FoundActors.Num() == 0) {
		UE_LOG(LogTemp, Error, TEXT("Player controller not found!"));
		return;
	}
	
	// Cast the found actor and do a null check.
	
	APlayerController* PlayerController = Cast<APlayerController>(FoundActors[0]);

	if (PlayerController == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Player controller couldn't be casted!"));
		return;
	}

	// If everything works, set our custom static camera as the one to be used by the controller.

	PlayerController->SetViewTarget(this);
	UE_LOG(LogTemp, Log, TEXT("Setting our camera as the view target!"));
}
