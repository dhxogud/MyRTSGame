// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYRTSGAME_API AInGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

	bool bShouldDrawBox = false;

	FVector2D TopLeft;
	FVector2D BottomRight;
};
