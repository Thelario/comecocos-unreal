// Fill out your copyright notice in the Description page of Project Settings.

#include "GemActor.h"

AGemActor::AGemActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Añadimos un cubo como malla de la gema.
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube"));
	MeshComponent->SetStaticMesh(MeshAsset.Object);
	MeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGemActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorRotation(FRotator(45, 45, 45));
}

// Called every frame
void AGemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

