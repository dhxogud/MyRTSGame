// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "InGameGS.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventDispatcher_UpdateGameTime, double, ElapsedGameTime);

UCLASS()
class MYRTSGAME_API AInGameGS : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void UpdateGameTime();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FEventDispatcher_UpdateGameTime EventDispatcher_UpdateGameTime;

	UPROPERTY(Replicated, VisibleAnywhere, Category = "Data", BlueprintReadOnly)
	double ElapsedGameTime;

	FTimerHandle GameTimerHandle;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};
