// Fill out your copyright notice in the Description page of Project Settings.


#include "NodeMapManager.h"

// Sets default values
ANodeMapManager::ANodeMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANodeMapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANodeMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

