// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay(){
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayController possesing: %s"), *(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank> (GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Tick is ticking"));
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}

	//get world location if liinetrace through crosshair
	// if it hits the landscape
		//tell controlled tank to aim at that point
}