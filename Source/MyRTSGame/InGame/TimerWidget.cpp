// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "Components/TextBlock.h"

void UTimerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	
}

void UTimerWidget::UpdateGameTime(double InElapsedGameTimedouble)
{
	if (TimeText)
	{
		TimeText->SetText(FText::AsNumber(InElapsedGameTimedouble));
	}
}