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
	AInGamePC();

	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnPossess(APawn* aPawn) override;

	virtual void OnUnPossess() override;


	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> IMC_Default;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> IA_Click;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> IA_SetDestination;

	UPROPERTY(EditAnywhere, Category = "Input", BlueprintReadWrite)
	TObjectPtr<UInputAction> IA_Zoom;

	UPROPERTY(VisibleAnywhere, Category = "Data", BlueprintReadOnly)
	TArray<AActor*> ControlledUnitGroups;

	void OnPointerDown(const FInputActionValue& Value);

	void OnPointerUp(const FInputActionValue& Value);

	void OnZoom(const FInputActionValue& Value);

	void GetActorsInDragBound();

	uint8 bIsDragging : 1;

	FVector2D CurrentScreenMousePointerPosition;

	UPROPERTY(VisibleAnywhere, Category = "Value", BlueprintReadOnly)
	FVector2D DragStartPointerPosition;
	
};
