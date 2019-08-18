// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"
// forward declarations

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	//how close the ai tank can get to player
	UPROPERTY(EditDefaultsOnly, Category = "Setup") //Consider 
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;
	//ATank* GetControlledTank() const;
	//ATank* GetPlayerTank() const;

	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
