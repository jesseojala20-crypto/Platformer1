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

	Starting_Location = GetActorLocation();

}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	MovePlatform(DeltaTime);
	RotatingPlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatFormVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	MovedDistance = FVector::Dist(Starting_Location, CurrentLocation);

	if (MovedDistance >= MoveLocation)
	{
	float Overshoot = (MoveLocation - MovedDistance);
		FString PlatformName = GetName();
		UE_LOG( LogTemp, Display, TEXT(" %s overshot by %f "), *PlatformName, Overshoot); // this here tells the name of the object and how much it has overshot
		
		PlatFormVelocity = -PlatFormVelocity;
		CurrentLocation = Starting_Location;
	}
	

}
void AMovingPlatform::RotatingPlatform(float DeltaTime)
{
	// rotate the platform
}