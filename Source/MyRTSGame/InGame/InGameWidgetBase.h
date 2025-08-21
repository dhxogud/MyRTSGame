// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class MYRTSGAME_API UInGameWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UInGameWidgetBase();
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void ShowInGamePanel();
	void HideInGamePanel();
	void VisibleSettingWidget();
	void CollapasedSettingWidget();

public:
	// 설정창, 미니맵, 유닛 컨트롤 패널, 유닛 모음 정보창, 유닛 초상화
};
