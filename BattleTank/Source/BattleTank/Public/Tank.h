// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put new includes above

// Forward declarations
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// TODO remvoe once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning pojectile
	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};