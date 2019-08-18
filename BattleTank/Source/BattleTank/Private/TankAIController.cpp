// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
void ATankAIController::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
		
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm

		// aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		
		//fire shot
		if (AimingComponent->GetFiringState() == EFiringState::Locked) {
			AimingComponent->Fire();
		}
}

