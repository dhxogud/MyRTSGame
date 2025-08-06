// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"
#include "CanvasItem.h"
#include "InGamePC.h"
#include "GameFramework/Character.h"

void AInGameHUD::DrawHUD()
{
	Super::DrawHUD();

	AInGamePC* PC = Cast<AInGamePC>(GetOwningPlayerController());
	if (IsValid(PC) && PC->bIsDragging)
	{
		TopLeft = FVector2D(FMath::Min(PC->CurrentScreenMousePointerPosition.X, PC->DragStartPointerPosition.X),
			FMath::Min(PC->CurrentScreenMousePointerPosition.Y, PC->DragStartPointerPosition.Y));

		BottomRight = FVector2D(FMath::Max(PC->CurrentScreenMousePointerPosition.X, PC->DragStartPointerPosition.X),
			FMath::Max(PC->CurrentScreenMousePointerPosition.Y, PC->DragStartPointerPosition.Y));

		float Width = BottomRight.X - TopLeft.X;
		float Height = BottomRight.Y - TopLeft.Y;

		DrawRect(struct FLinearColor(0, 0, 0, 0.3f), TopLeft.X, TopLeft.Y, Width, Height);

		
		TArray<AActor*> OutActors;
		GetActorsInSelectionRectangle(ACharacter::StaticClass(), TopLeft, BottomRight, OutActors, false, false);

		if (OutActors.Num() > 0)
		{
			SelectedUnits.Empty();
			for (AActor* Actor : OutActors)
			{
				ACharacter* Character = Cast<ACharacter>(Actor);
				SelectedUnits.Add(Character);
			}
		}

	}
}

