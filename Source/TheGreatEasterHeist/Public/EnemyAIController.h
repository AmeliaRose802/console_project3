// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATEASTERHEIST_API AEnemyAIController final : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();

	UFUNCTION(BlueprintCallable)
	void PauseBehaviorTree() const;
	UFUNCTION(BlueprintCallable)
	void UnPauseBehaviorTree() const;

	virtual void OnPossess(APawn* InPawn) override;

public:
	uint8 TargetLocationKeyID;
	uint8 SelfActorKeyID;

protected:
	UPROPERTY(Transient)
	class UBlackboardComponent* BlackboardComponent;

	UPROPERTY(Transient)
	class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bStartBehaviorTreePaused = false;
};
