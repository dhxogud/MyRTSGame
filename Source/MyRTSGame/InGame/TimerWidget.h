// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

/**
 * 
 */
class UTextBlock;

UCLASS()
class MYRTSGAME_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void UpdateGameTime(double InElapsedGameTimedouble);

	UPROPERTY(meta=(BindWidgetOptional), VisibleAnywhere, Category = "UI", BlueprintReadOnly)
	TObjectPtr<UTextBlock> TimeText;
};
