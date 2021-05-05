// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelGenerator.generated.h"

/**
 * 
 */

/*
struct{
actor
probability 
}
*/
UCLASS()
class THEGREATEASTERHEIST_API ALevelGenerator final : public AActor
{
	GENERATED_BODY()
	
public:
	ALevelGenerator();

	//Variables
	//Types of obstacles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TSubclassOf<AActor>, float> LevelObjects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> FloorClass;

	//Types of tiles
	//Power-ups
	//Coins

	//Weighted random functions
	TSubclassOf<AActor> PickRandomIndex(TMap<TSubclassOf<AActor>, float> Map);


	//Spawn function for floor

	UFUNCTION(BlueprintCallable)
	AActor* SpawnFloor(FTransform AttachPoint) const;

	//Spawn function for level object
	UFUNCTION(BlueprintCallable)
	void SpawnLevelObject(TArray<FTransform> SpawnPoints, int NumPoints);

};
