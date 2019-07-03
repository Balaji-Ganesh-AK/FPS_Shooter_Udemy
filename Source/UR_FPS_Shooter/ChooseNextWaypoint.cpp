// Fill out your copyright notice in the Description page of Project Settings.


#include "UR_FPS_Shooter.h"
#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get the patrol waypoints
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	// check for Empty Patrol Points
	if (PatrolPoints.Num()==0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Please add Patrol point to one of the gaurd"));
		return EBTNodeResult::Failed;

	}

	//UE_LOG(LogTemp, Warning,  TEXT("%s"),*AIController->GetName());
	//Set the next waypoint
	auto BlackBoardComponent = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("%i"), Index);
	BlackBoardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	//cycle the waypoints	
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	
	BlackBoardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	return EBTNodeResult::Succeeded;
}
