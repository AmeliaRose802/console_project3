// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/UnrealMathUtility.h"
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
class THEGREATEASTERHEIST_API ULevelGenerator final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	ULevelGenerator();

	//Weighted random functions
	static TSubclassOf<AActor> PickRandomIndex(TMap<TSubclassOf<AActor>, float> Map);


	//Spawn function for floor

	UFUNCTION(BlueprintCallable)
	static AActor* SpawnFloor(FTransform AttachPoint, TSubclassOf<AActor> FloorClass, UObject* WorldContextObject);

	//Spawn function for level object
	UFUNCTION(BlueprintCallable)
	static void SpawnLevelObject(TArray<FTransform> SpawnPoints, int NumPoints, TMap<TSubclassOf<AActor>, float> LevelObjects, UObject* WorldContextObject);

};
