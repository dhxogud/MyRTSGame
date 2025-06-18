// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNode.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseNode::ABaseNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);
}

// Called when the game starts or when spawned
void ABaseNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

