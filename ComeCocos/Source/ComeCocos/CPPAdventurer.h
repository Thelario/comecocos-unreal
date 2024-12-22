// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "GameSpawner.h"
#include "Components/SphereComponent.h"
#include "CPPAdventurer.generated.h"

UCLASS()
class COMECOCOS_API ACPPAdventurer : public APawn
{
	GENERATED_BODY()

	AGameSpawner* GameSpawner;

	UPROPERTY(VisibleAnywhere, Category = "Trigger Sphere")
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	
public:
	// El mapping context
	UInputMappingContext* _input_mapping_context;

	// Una acción (puede haber más)
	UInputAction* _move;

	// Sets default values for this pawn's properties
	ACPPAdventurer();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void BeginPlay() override;
	
public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& v);
};
