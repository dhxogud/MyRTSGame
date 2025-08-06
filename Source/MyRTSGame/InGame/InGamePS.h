// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "InGamePS.generated.h"

/**
 * 
 */
UCLASS()
class MYRTSGAME_API AInGamePS : public APlayerState
{
	GENERATED_BODY()
public:
	// 최대 인구수
	// 최대 자원량 (미네랄)
	// 최대 자원량 (가스)
};
