// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "Components/TextBlock.h"

void UTimerWidget::NativeConstruct()
{
	if (!TimeText)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed To Find Widget Component : TimeText "));
	}

}
