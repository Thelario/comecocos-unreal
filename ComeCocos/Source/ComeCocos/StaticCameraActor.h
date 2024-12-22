// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "StaticCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class COMECOCOS_API AStaticCameraActor : public ACameraActor
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
};
