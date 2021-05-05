// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGenerator.h"

ALevelGenerator::ALevelGenerator()
{

}

TSubclassOf<AActor> ALevelGenerator::PickRandomIndex(TMap<TSubclassOf<AActor>, float> Map)
{
    //https://stackoverflow.com/questions/1761626/weighted-random-numbers
    float Sum_Weights = 0;

    for (const TPair<TSubclassOf<AActor>, float>& Pair : Map)
    {
        Sum_Weights += Pair.Value;
    }

    const float Rand = FMath::RandRange(0.0, Sum_Weights);

    float SoFar = 0;
    for (const TPair<TSubclassOf<AActor>, float>& Pair : Map) {
        SoFar += Pair.Value;
        if (Rand >= SoFar) {
            return Pair.Key;
        }
    }

    //Fallback, should never reach here
    TArray<TSubclassOf<AActor>> KeyArray;
    Map.GenerateKeyArray(KeyArray);
    return KeyArray[0];
}

//Spawn function for floor
AActor * ALevelGenerator::SpawnFloor(const FTransform AttachPoint) const
{
    const FActorSpawnParameters SpawnParameters;
    return GetWorld()->SpawnActor<AActor>(
        FloorClass, AttachPoint.GetLocation(),
        AttachPoint.GetRotation().Rotator(),
        SpawnParameters);
    
}

//Spawn function for level object
void ALevelGenerator::SpawnLevelObject(TArray<FTransform> SpawnPoints, const int NumPoints)
{
    const int SpawnPointIndex = FMath::RandRange(0, NumPoints);
    const FActorSpawnParameters SpawnParameters;
    GetWorld()->SpawnActor<AActor>(
        PickRandomIndex(LevelObjects),
        SpawnPoints[SpawnPointIndex].GetLocation(),
        SpawnPoints[SpawnPointIndex].GetRotation().Rotator(),
        SpawnParameters);
}