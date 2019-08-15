// Copyright EmbraceIT Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h" //must be last inlude

//forward declarations
class ATank;
class UTankAimingComponent;
/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;	

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	//start moving tank barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = .5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = .333333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
