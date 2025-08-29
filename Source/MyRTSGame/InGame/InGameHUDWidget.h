// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameHUDWidget.generated.h"

/**
 * 
 */

UCLASS()
class MYRTSGAME_API UInGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	void ShowDefaultInGamePanels();
	void HideDefaultInGamePanels();
	void UpdateGameTime(double InElapsedGameTimedouble);
	

public:
	// GamePlaying
	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> MiniMapPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> TimerPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> InforPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> PortraitPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> CommandPanel;

	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> ResourcePanel;


	// NetWork
	UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	TObjectPtr<UUserWidget> ChatPanel;

	//UPROPERTY(EditAnyWhere, Category = "UI", BlueprintReadWrite)
	//TObjectPtr<UUserWidget> AlertPanel; 이건 따로 패널 만들지 말고 텍스트 한줄 띄우자 그냥
};
