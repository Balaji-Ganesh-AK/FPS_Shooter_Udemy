// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolRouteComponent.h"
#include "UR_FPS_Shooter.h"

TArray<AActor*> UPatrolRouteComponent::GetPatrolPoints() const
{
	return PatrolPoints;
}