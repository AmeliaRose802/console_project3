// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Level_Generator.h"

CPP_Level_Generator::CPP_Level_Generator()
{

}

CPP_Level_Generator::~CPP_Level_Generator()
{
}


AActor * CPP_Level_Generator::PickRandomIndex(TMap<AActor*, float> map) {

    //https://stackoverflow.com/questions/1761626/weighted-random-numbers
    float sum_weights = 0;

    for (const TPair<AActor*, float>& pair : map)
    {
        sum_weights += pair.Value;
    }

    float rand = FMath::RandRange(0.0, sum_weights);

    float soFar = 0;
    for (const TPair<AActor*, float>& pair : map) {
        soFar += pair.Value;
        if (rand >= soFar) {
            return pair.Key;
        }

        
    }
     
}


//Spawn function for floor

AActor * CPP_Level_Generator::SpawnFloor(FTransform attachPoint) {
    return GetWorld()->SpawnActor<AActor>(floor::StaticClass(), NAME_None, attachPoint.GetLocation());
    
}

//Spawn function for level object
void CPP_Level_Generator::SpawnLevelObject(FTransform spawnPoints [], int numPoints) {
    int spawnPointIndex = FMath::RandRange(0, numPoints);
    GetWorld()->SpawnActor(PickRandomIndex(levelObjects), NAME_None, spawnPoints[spawnPointIndex].GetLocation());
}