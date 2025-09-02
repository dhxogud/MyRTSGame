// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniMapWidget.h"
#include "Components/OverlaySlot.h"
#include "Components/Button.h"
#include "Components/Image.h"

void UMiniMapWidget::NativeConstruct()
{
	if (AllStandByWorkerSelectButton)
	{
		AllStandByWorkerSelectButton->OnClicked.AddDynamic(this, &UMiniMapWidget::OnClickAllStandByWorkerSelectButton);
	}

	if (AllStandByCombatUnitSelectButton)
	{
		AllStandByCombatUnitSelectButton->OnClicked.AddDynamic(this, &UMiniMapWidget::OnClickAllStandByCombatUnitSelectButton);
	}

	if (SendSignalButton)
	{
		SendSignalButton->OnClicked.AddDynamic(this, &UMiniMapWidget::OnClickSendSignalButton);
	}

	if (MinimapTerrainToggleButton)
	{
		MinimapTerrainToggleButton->OnClicked.AddDynamic(this, &UMiniMapWidget::OnClickMinimapTerrainToggleButton);
	}

	if (AllianceColorModeToggleButton)
	{
		AllianceColorModeToggleButton->OnClicked.AddDynamic(this, &UMiniMapWidget::OnClickAllianceColorModeToggleButton);
	}

}

void UMiniMapWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

}

void UMiniMapWidget::OnClickMapOverlayPanel()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClick : OnClickMapOverlayPanel"));
}

void UMiniMapWidget::OnClickAllStandByWorkerSelectButton()
{
	
}

void UMiniMapWidget::OnClickAllStandByCombatUnitSelectButton()
{
	
}

void UMiniMapWidget::OnClickSendSignalButton()
{
	
}

void UMiniMapWidget::OnClickMinimapTerrainToggleButton()
{
	
}

void UMiniMapWidget::OnClickAllianceColorModeToggleButton()
{
	
}
