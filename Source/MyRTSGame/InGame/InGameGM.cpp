// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameGM.h"
#include "TimerManager.h"
#include "InGameGS.h"

void AInGameGM::BeginPlay()
{
	UWorld* World = GetWorld();
	if (World)
	{
		World->GetTimerManager().SetTimer(
			GameTimerHandle,
			this,
			&AInGameGM::UpdateGameTimePerSecond,
			1.0f,
			true
		);
	}

}

void AInGameGM::UpdateGameTimePerSecond()
{
	AInGameGS* GS = GetGameState<AInGameGS>();
	if (GS)
	{
		GS->ElapsedGameTime += 1.0f;
		GS->OnRep_ElapsedGameTime();
	}
}
