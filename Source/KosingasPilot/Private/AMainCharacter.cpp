// Fill out your copyright notice in the Description page of Project Settings.


#include "AMainCharacter.h"

// Sets default values
AAMainCharacter::AAMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAMainCharacter::VaultObstacleDetection(const int32 index, FVector& Start, FVector& End)
{
	Start = GetActorLocation();
	Start.Z += index * 30;

	End = GetActorRotation().Vector();
	End *= FVector(180, 180, 180);

	End = Start + End;
	
}

void AAMainCharacter::VaultMovement(const int32 index, const FVector& ObstacleLocation, FVector& Start, FVector& End)
{
	const int SEPARATION = index * 50;
	FVector ActorDirection = GetActorRotation().Vector();
	ActorDirection *= FVector(SEPARATION, SEPARATION, SEPARATION);
	
	Start = ObstacleLocation;
	Start.Z += 100;

	Start += ActorDirection;

	End = Start;
	End.Z -= 100;

}

void AAMainCharacter::EndVault(const FVector& ObstacleEndLocation, FVector& Start, FVector& End)
{
	FVector ActorDirection = GetActorRotation().Vector();
	ActorDirection *= FVector(80, 80, 80);

	Start = ObstacleEndLocation + ActorDirection;

	End = Start;
	End.Z -= 1000;
	
}


