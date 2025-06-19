// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"
#include "CanvasItem.h"
#include "InGamePC.h"
#include "GameFramework/Pawn.h"

void AInGameHUD::DrawHUD()
{
	AInGamePC* PC = Cast<AInGamePC>(GetOwningPlayerController());
	if (IsValid(PC))
	{
		if (PC->bIsDragging)
		{
			TopLeft = FVector2D(FMath::Min(PC->DragStartPosition.X, PC->DragEndPosition.X),
				FMath::Min(PC->DragStartPosition.Y, PC->DragEndPosition.Y));

			BottomRight = FVector2D(FMath::Max(PC->DragStartPosition.X, PC->DragEndPosition.X),
				FMath::Max(PC->DragStartPosition.Y, PC->DragEndPosition.Y));

			float Width = BottomRight.X - TopLeft.X;
			float Height = BottomRight.Y - TopLeft.Y;

			DrawRect(struct FLinearColor(0, 0, 0, 0.3f), TopLeft.X, TopLeft.Y, Width, Height);

		}
	}
}

