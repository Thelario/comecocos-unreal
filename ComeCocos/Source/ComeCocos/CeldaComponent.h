// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAdventurer.h"
#include "Components/ActorComponent.h"
#include "CeldaComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMECOCOS_API UCeldaComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	double _height = 90.0f;

	UPROPERTY(EditAnywhere)
	ACPPAdventurer* _adventurer;
	
public:	
	// Sets default values for this component's properties
	UCeldaComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
