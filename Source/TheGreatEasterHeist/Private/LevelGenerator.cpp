// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGenerator.h"

ULevelGenerator::ULevelGenerator()
{

}

TSubclassOf<AActor> ULevelGenerator::PickRandomIndex(TMap<TSubclassOf<AActor>, float> Map)
{

    
    //https://stackoverflow.com/questions/1761626/weighted-random-numbers
    int Sum_Weights = 0;

    for (const TPair<TSubclassOf<AActor>, float>& Pair : Map)
    {
        Sum_Weights += Pair.Value;
    }

    int RandNum = FMath::RandRange(0, Sum_Weights);
   // GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, TEXT(FMath::RandRange(0.0, Sum_Weights)));

    int SoFar = 0;
    for (const TPair<TSubclassOf<AActor>, float>& Pair : Map) {
        SoFar += Pair.Value;
        if (RandNum <= SoFar) {
            return Pair.Key;
        }
    }
    
    //Fallback, should never reach here
    TArray<TSubclassOf<AActor>> KeyArray;
    Map.GenerateKeyArray(KeyArray);

    int ARandNum = FMath::RandRange(0, 1);

    return KeyArray[ARandNum];
}

//Spawn function for floor
 AActor* ULevelGenerator::SpawnFloor(FTransform AttachPoint, TSubclassOf<AActor> FloorClass, UObject* WorldContextObject)
{
    FActorSpawnParameters SpawnParameters;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    SpawnParameters.bNoFail = true;
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);

    return World->SpawnActor<AActor>(
        FloorClass, AttachPoint.GetLocation(),
        AttachPoint.GetRotation().Rotator(),
        SpawnParameters);
    
}

//Spawn function for level object
void ULevelGenerator::SpawnLevelObject(TArray<FTransform> SpawnPoints, int NumPoints, TMap<TSubclassOf<AActor>, float> LevelObjects, UObject* WorldContextObject)
{
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);

    const int SpawnPointIndex = FMath::RandRange(0, NumPoints-1);
    const FActorSpawnParameters SpawnParameters;
        World->SpawnActor<AActor>(
            ULevelGenerator::PickRandomIndex(LevelObjects),
        SpawnPoints[SpawnPointIndex].GetLocation(),
        SpawnPoints[SpawnPointIndex].GetRotation().Rotator(),
        SpawnParameters);
}