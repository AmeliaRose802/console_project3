// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class THEGREATEASTERHEIST_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

public:
	UPROPERTY(EditAnywhere, Category=Behavior)
	class UBehaviorTree* BehaviorTree;
};
