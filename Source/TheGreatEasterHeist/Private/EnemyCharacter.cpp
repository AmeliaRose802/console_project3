// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "EnemyAIController.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	AIControllerClass = AEnemyAIController::StaticClass();
}