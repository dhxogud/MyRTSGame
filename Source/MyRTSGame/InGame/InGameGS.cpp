// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameGS.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"

void AInGameGS::BeginPlay()
{
	if (HasAuthority())
	{
		UWorld* World = GetWorld();
		if (World)
		{
			World->GetTimerManager().SetTimer(GameTimerHandle, this, &AInGameGS::UpdateGameTime, 1.0f, true);
		}
	}
	
}

void AInGameGS::UpdateGameTime()
{
	ElapsedGameTime += 1.0f;
	EventDispatcher_UpdateGameTime.Broadcast(ElapsedGameTime);
}

void AInGameGS::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInGameGS, ElapsedGameTime);

}
