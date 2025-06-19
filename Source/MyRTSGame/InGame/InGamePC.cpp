// Fill out your copyright notice in the Description page of Project Settings.
#include "InGamePC.h"
#include "InGamePawn.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InGameHUD.h"
#include "GameFramework/Pawn.h"

void AInGamePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(InputComponent);

	if (UEIC)
	{
		UEIC->BindAction(IA_LeftClick, ETriggerEvent::Started, this, &AInGamePC::OnStartDrag);
		UEIC->BindAction(IA_LeftClick, ETriggerEvent::Triggered, this, &AInGamePC::OnTriggerDrag);
		UEIC->BindAction(IA_LeftClick, ETriggerEvent::Completed, this, &AInGamePC::OnEndDrag);
		UEIC->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &AInGamePC::OnZoom);
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AInGamePC::OnMove);
	}
}

void AInGamePC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

void AInGamePC::OnStartDrag(const FInputActionValue& Value)
{
	bIsDragging = true;
	GetMousePosition(DragStartPosition.X, DragStartPosition.Y);
}

void AInGamePC::OnTriggerDrag(const FInputActionValue& Value)
{

	GetMousePosition(DragEndPosition.X, DragEndPosition.Y);
}

void AInGamePC::OnEndDrag(const FInputActionValue& Value)
{
	bIsDragging = false;

	AInGameHUD* HUD = Cast<AInGameHUD>(GetHUD());
	if (HUD)
	{
		ControlledGroups.Empty();

		for (auto Actor : HUD->ActorsInDragBox)
		{
			ControlledGroups.AddUnique(Actor);
		}
		//for (auto InPawn : ControlledGroups)
		//{
		//	UE_LOG(LogTemp, Warning, TEXT("Selected Actor : %s"), *InPawn->GetName());
		//}
	}
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
