// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "InGameGS.h"

void UTimerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AInGameGS* GS = Cast<AInGameGS>(UGameplayStatics::GetGameState(GetWorld()));
	if (GS)
	{
		GS->EventDispatcher_UpdateGameTime.AddDynamic(this, &UTimerWidget::UpdateGameTime);
	}
}

void UTimerWidget::UpdateGameTime(double InElapsedGameTimedouble)
{
	if (TimeText)
	{
		TimeText->SetText(FText::AsNumber(InElapsedGameTimedouble));
	}
}