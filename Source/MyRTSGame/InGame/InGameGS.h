// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "InGameGS.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventDispatcher_ElapsedGameTime, double, InElapsedGameTime);

UCLASS()
class MYRTSGAME_API AInGameGS : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(ReplicatedUsing = OnRep_ElapsedGameTime, VisibleAnywhere, Category = "Data", BlueprintReadOnly)
	double ElapsedGameTime;

	UPROPERTY(BlueprintAssignable)
	FEventDispatcher_ElapsedGameTime EventElapsedGameTime;

	UFUNCTION()
	void OnRep_ElapsedGameTime();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};
