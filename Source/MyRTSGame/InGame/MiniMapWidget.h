// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MiniMapWidget.generated.h"

/**
 * 
 */
class UButton;
class UImage;
class UOverlaySlot;

UCLASS()
class MYRTSGAME_API UMiniMapWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:

	UPROPERTY(meta = (BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> TimerWidget;

	UPROPERTY(meta=(BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UOverlaySlot> MapOverlayPanel;

	UPROPERTY(meta = (BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UImage> MapImage;

	UPROPERTY(meta=(BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UButton> AllStandByWorkerSelectButton;

	UPROPERTY(meta=(BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UButton> AllStandByCombatUnitSelectButton;

	UPROPERTY(meta = (BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UButton> SendSignalButton;
	 
	UPROPERTY(meta = (BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UButton> MinimapTerrainToggleButton;

	UPROPERTY(meta = (BindWidgetOptional), EditAnywhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UButton> AllianceColorModeToggleButton;

	UFUNCTION()
	void OnClickMapOverlayPanel();

	UFUNCTION()
	void OnClickAllStandByWorkerSelectButton();

	UFUNCTION()
	void OnClickAllStandByCombatUnitSelectButton();

	UFUNCTION()
	void OnClickSendSignalButton();

	UFUNCTION()
	void OnClickMinimapTerrainToggleButton();

	UFUNCTION()
	void OnClickAllianceColorModeToggleButton();


};
