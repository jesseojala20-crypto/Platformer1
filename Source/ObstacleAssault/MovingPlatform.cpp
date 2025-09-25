// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void MyTestFunction1 (float MyFloatParam1, FString MyString2)
{
	UE_LOG(LogTemp, Display, TEXT("MyFloatParam is %f"), MyFloatParam1);
	UE_LOG(LogTemp, Display, TEXT("MystringParam is %s"), *MyString2);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
   
	FVector TestVector = FVector(560.0f, -60.0f, 360.0f);

	FString MyName = GetName();
	MyTestFunction1(3.5f, MyName);

}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatFormVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

}

void AMovingPlatform::RotatingPlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("This will rotate the platform"));
}
