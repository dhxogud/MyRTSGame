// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "InGameGS.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventDispatcher_UpdateGameTime, uint16, ElapsedGameTime);

UCLASS()
class MYRTSGAME_API AInGameGS : public AGameStateBase
{
	GENERATED_BODY()
	
protected:
	virtual void UpdateServerTimeSeconds() override;

public:
	UPROPERTY(Replicated, VisibleAnywhere, Category = "Data", BlueprintReadOnly)
	double ElapsedGameTime;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FEventDispatcher_UpdateGameTime EventDispatcher_UpdateGameTime;


	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
};
