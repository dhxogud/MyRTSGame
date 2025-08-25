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
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void ShowDefaultInGamePanels();
	void HideDefaultInGamePanels();
	

public:
	// GamePlaying
	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> MiniMapPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> TimerPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> UnitInforPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> UnitPortraitPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> UnitControlPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> ResourceInforPanel;


	// NetWork
	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> ChattingPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> AlertPanel;

};
