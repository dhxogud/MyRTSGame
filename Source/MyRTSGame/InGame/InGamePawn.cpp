// Fill out your copyright notice in the Description page of Project Settings.


#include "InGamePawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

// Sets default values
AInGamePawn::AInGamePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->SetupAttachment(Capsule);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 800.0f;
	SpringArm->SetRelativeRotation(FRotator(-70.0f, 0, 0));
}

// Called when the game starts or when spawned
void AInGamePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInGamePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AInGamePawn::OnCameraZoom(float Value)
{
	SpringArm->TargetArmLength += Value * -10.0f;
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength,
		100.0f,
		600.0f);
}

void AInGamePawn::OnCameraMove(FVector2D Value)
{

}
