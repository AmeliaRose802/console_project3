// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "EnemyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

AEnemyAIController::AEnemyAIController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

void AEnemyAIController::PauseBehaviorTree() const
{
	BehaviorTreeComponent->PauseLogic("Pause");
}

void AEnemyAIController::UnPauseBehaviorTree() const
{
	BehaviorTreeComponent->ResumeLogic("Resume");
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AEnemyCharacter* Char = Cast<AEnemyCharacter>(InPawn);

	if (Char && Char->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Char->BehaviorTree->BlackboardAsset);

		TargetLocationKeyID = BlackboardComponent->GetKeyID("TargetLocation");
		SelfActorKeyID = BlackboardComponent->GetKeyID("SelfActor");
		BlackboardComponent->SetValue<UBlackboardKeyType_Object>(SelfActorKeyID, Char);

		BehaviorTreeComponent->StartTree(*Char->BehaviorTree);

		if (bStartBehaviorTreePaused)
		{
			PauseBehaviorTree();
		}
	}
}
