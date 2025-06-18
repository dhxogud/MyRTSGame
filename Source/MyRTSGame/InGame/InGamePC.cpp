// Fill out your copyright notice in the Description page of Project Settings.
#include "InGamePC.h"
#include "InGamePawn.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

void AInGamePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(InputComponent);

	if (UEIC)
	{
		UEIC->BindAction(IA_LeftClick, ETriggerEvent::Started, this, &AInGamePC::OnStartClick);
		UEIC->BindAction(IA_LeftClick, ETriggerEvent::Completed, this, &AInGamePC::OnEndClick);
		UEIC->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &AInGamePC::OnZoom);
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AInGamePC::OnMove);
	}
}

void AInGamePC::Tick(float DeltaTime)
{
	if (bIsDragging)
	{
		UE_LOG(LogTemp, Warning,
			TEXT("DragMinScreen : %f X %f Y"),
			FMath::Min(DragStartScreen.X, DragEndScreen.X),
			FMath::Min(DragStartScreen.Y, DragEndScreen.Y));
		UE_LOG(LogTemp, Warning,
			TEXT("DragMaxScreen : %f X %f Y"),
			FMath::Max(DragStartScreen.X, DragEndScreen.X),
			FMath::Max(DragStartScreen.Y, DragEndScreen.Y));
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

void AInGamePC::OnStartClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Drag!"));
	bIsDragging = true;
	GetMousePosition(DragStartScreen.X, DragStartScreen.Y);
}

void AInGamePC::OnEndClick()
{
	UE_LOG(LogTemp, Warning, TEXT("End Drag!"));
	bIsDragging = false;
	GetMousePosition(DragEndScreen.X, DragEndScreen.Y);
	GetActorsInDragBound();
}

void AInGamePC::OnZoom(const FInputActionValue& Value)
{
	
}

void AInGamePC::OnMove(const FInputActionValue& Value)
{

}

void AInGamePC::GetActorsInDragBound()
{

}
