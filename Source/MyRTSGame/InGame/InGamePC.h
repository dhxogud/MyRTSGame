// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InGamePC.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class MYRTSGAME_API AInGamePC : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* aPawn) override;

	virtual void OnUnPossess() override;


	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> IMC_Default;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> IA_LeftClick;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> IA_Zoom;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> IA_Move;

	uint8 bIsDragging : 1;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> ControlledActors;

	FVector2D DragStartScreen;

	FVector2D DragEndScreen;

	void OnStartClick();

	void OnEndClick();

	void OnZoom(const FInputActionValue& Value);

	void OnMove(const FInputActionValue& Value);

	void GetActorsInDragBound();
};
