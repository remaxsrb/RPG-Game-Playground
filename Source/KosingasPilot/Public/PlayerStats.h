// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterStats.h"
#include "Components/ActorComponent.h"
#include "PlayerStats.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KOSINGASPILOT_API UPlayerStats : public UCharacterStats
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Resources")
	int32 Gold = 200;
		
};
