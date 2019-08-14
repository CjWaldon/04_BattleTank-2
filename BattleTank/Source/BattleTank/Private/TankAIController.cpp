// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
void ATankAIController::BeginPlay() {
	Super::BeginPlay();

}




// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) {

		auto ControlledTank = Cast<ATank>(GetPawn());
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm

		// aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//fire shot
		ControlledTank->Fire(); //TODO limit firing rate
	}

}

