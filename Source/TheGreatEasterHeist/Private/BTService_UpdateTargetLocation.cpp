// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateTargetLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void UBTService_UpdateTargetLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		const FVector PlayerCharacterLocation = PlayerCharacter->GetActorLocation();

		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(FName("TargetLocation"), PlayerCharacterLocation);
	}
}
