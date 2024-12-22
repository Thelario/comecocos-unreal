// Fill out your copyright notice in the Description page of Project Settings.
 
#include "CPPAdventurer.h"

#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"

ACPPAdventurer::ACPPAdventurer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Damos forma para las colisiones
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(50.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// Así se crea un componente para este actor
	auto Move = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement Component"));
	Move->MaxSpeed = 1200.0f;

	// Añadimos la mesh de la esfera
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere"));
	MeshComponent->SetStaticMesh(MeshAsset.Object);
	MeshComponent->SetupAttachment(RootComponent);

	_move = CreateDefaultSubobject<UInputAction>(TEXT("MoveAction"));
	_input_mapping_context = CreateDefaultSubobject<UInputMappingContext>(TEXT("NormalMapping"));	
}

void ACPPAdventurer::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("Overlap notification!!"));
	
	// Decrease gem amount if game spawner found.
	
	if (GameSpawner != nullptr) {
		GameSpawner->DecreaseGems(1);
	} else {
		UE_LOG(LogTemp, Error, TEXT("Game spawner is nullptr!!"));
	}

	// Destroy gem.
	
	GetWorld()->DestroyActor(OtherActor);
}

void ACPPAdventurer::BeginPlay()
{
	Super::BeginPlay();

	// Find game spawner in the world.
	
	TSubclassOf<AGameSpawner> GameSpawnerClass = AGameSpawner::StaticClass();
	TArray<AActor*> FoundTargets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), GameSpawnerClass, FoundTargets);
	
	if (FoundTargets.Num() > 0) {
		GameSpawner = static_cast<AGameSpawner*>(FoundTargets[0]);
	} else {
		UE_LOG(LogTemp, Error, TEXT("No game spawner found!!"));
		GameSpawner = nullptr;
	}
}

// Called to bind functionality to input
void ACPPAdventurer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto controller = Cast<APlayerController>(GetController());
	if (auto system = controller->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) {
		if (_input_mapping_context) {
			// el "1" es la prioridad del mapeo, cuanto más alta, más prioritario
			system->AddMappingContext(_input_mapping_context, 1);

			_move->bConsumeInput = true;
			_move->ValueType = EInputActionValueType::Axis1D;

			// hay más maneras de instanciar la tecla (FKey("W"))
			_input_mapping_context->MapKey(_move, EKeys::W);

			auto & mapping = _input_mapping_context->MapKey(_move, EKeys::S);
			mapping.Modifiers.Add(NewObject<UInputModifierNegate>(this));
		}
	}

	auto eic = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	eic->BindAction(_move, ETriggerEvent::Triggered, this, &ACPPAdventurer::Move);
}

void ACPPAdventurer::Move(const FInputActionValue& v)
{
	FVector forward = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraRotation().Vector();
	AddMovementInput(forward, v.GetMagnitude());
}
