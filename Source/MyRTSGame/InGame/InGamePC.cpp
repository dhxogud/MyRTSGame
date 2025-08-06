// Fill out your copyright notice in the Description page of Project Settings.
#include "InGamePC.h"
#include "InGamePawn.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InGameHUD.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetSystemLibrary.h"

AInGamePC::AInGamePC()
{
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bEnableTouchEvents = true;
	bEnableTouchOverEvents = true;
}

void AInGamePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(InputComponent);

	if (UEIC)
	{
		UEIC->BindAction(IA_Click, ETriggerEvent::Started, this, &AInGamePC::OnPointerDown);
		UEIC->BindAction(IA_Click, ETriggerEvent::Completed, this, &AInGamePC::OnPointerUp);

		//UEIC->BindAction(IA_SetDestination, ETriggerEvent::Triggered, this, &AInGamePC::OnMove);

		UEIC->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &AInGamePC::OnZoom);
	}
}

void AInGamePC::BeginPlay()
{
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetHideCursorDuringCapture(false);
	//InputMode.SetWidgetToFocus()
	SetInputMode(InputMode);
	bShowMouseCursor = true;
}


void AInGamePC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetMousePosition(CurrentScreenMousePointerPosition.X, CurrentScreenMousePointerPosition.Y);

	float MoveOffsetX = 10.0f;
	float MoveOffsetY = 10.0f;
	int32 SizeX;
	int32 SizeY;
	GetViewportSize(SizeX, SizeY);

	AInGamePawn* MyPawn = Cast<AInGamePawn>(GetPawn());
	if (MyPawn)
	{
		FVector Direction { 0.0f, 0.0f, 0.0f };

		if (CurrentScreenMousePointerPosition.X >= (SizeX - MoveOffsetX)) // 나중엔 Offset 같은 수치가 아니라 마우스 커서 크기에 맞춰 반응하도록 바꿀것임 지금은 일단
		{
			Direction += FVector::RightVector;
		}
		else if (CurrentScreenMousePointerPosition.X <= MoveOffsetX)
		{
			Direction += FVector::LeftVector;
		}

		if (CurrentScreenMousePointerPosition.Y >= (SizeY - MoveOffsetY))
		{
			Direction += FVector::BackwardVector;
		}
		else if (CurrentScreenMousePointerPosition.Y <= MoveOffsetY)
		{
			Direction += FVector::ForwardVector;
		}
		
		MyPawn->OnMove(Direction.GetSafeNormal2D() * DeltaTime);
	}
}

void AInGamePC::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	AInGamePawn* MyPawn = Cast<AInGamePawn>(aPawn);
	if (MyPawn)
	{
		if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem =
				LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (IMC_Default)
				{
					InputSystem->AddMappingContext(IMC_Default, 0);
				}
			}
		}
	}
}

void AInGamePC::OnUnPossess()
{
	Super::OnUnPossess();
}

void AInGamePC::OnPointerDown(const FInputActionValue& Value)
{
	bIsDragging = true;
	DragStartPointerPosition = CurrentScreenMousePointerPosition;
}

void AInGamePC::OnPointerUp(const FInputActionValue& Value)
{
	bIsDragging = false;
	

}

void AInGamePC::OnZoom(const FInputActionValue& Value)
{
	
}

void AInGamePC::GetActorsInDragBound()
{

}
