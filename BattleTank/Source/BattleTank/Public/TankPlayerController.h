// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h" //must be last inlude

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;	

private:
	ATank* GetControlledTank() const;
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	//start moving tank barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .333333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
