// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"

/**
 * 
 */

/*
struct{
actor
probility 
}
*/
class THEGREATEASTERHEIST_API CPP_Level_Generator : public AActor
{
public:
	CPP_Level_Generator();
	~CPP_Level_Generator();

	//Varibles
	//Types of obsticles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<AActor*, float> levelObjects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor * floor;

	//Types of tiles
	//Powerups
	//Coins

	//Weighted random functions
	AActor * PickRandomIndex(TMap<AActor*, float> map);


	//Spawn function for floor

	UFUNCTION(BlueprintCallable)
		AActor* SpawnFloor(FTransform attachPoint);

	//Spawn function for level object
	UFUNCTION(BlueprintCallable)
		void SpawnLevelObject(FTransform spawnPoints[], int numPoints);

};
