// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "AMainCharacter.generated.h"

UCLASS()
class KOSINGASPILOT_API AAMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Stats")
	float Health = 1000.0f;
	
	UFUNCTION(BlueprintCallable, Category = "Character|TraceLocations")
    void VaultObstacleDetection(const int32 index, FVector& Start, FVector& End);
     
    UFUNCTION(BlueprintCallable, Category = "Character|TraceLocations")
    void VaultMovement(const int32 index, const FVector& ObstacleLocation, FVector& Start, FVector& End);

	UFUNCTION(BlueprintCallable, Category = "Character|TraceLocations")
	void EndVault(const FVector& ObstacleEndLocation, FVector& Start, FVector& End);
    
    

};
