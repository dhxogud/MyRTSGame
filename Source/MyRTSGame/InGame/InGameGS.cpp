// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameGS.h"
#include "Net/UnrealNetwork.h"

void AInGameGS::OnRep_ElapsedGameTime()
{
	EventElapsedGameTime.Broadcast(ElapsedGameTime);

}

void AInGameGS::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInGameGS, ElapsedGameTime);

}
