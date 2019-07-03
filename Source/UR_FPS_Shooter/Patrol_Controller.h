// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Patrol_Controller.generated.h"

/**
 * 
 */
UCLASS()
class UR_FPS_SHOOTER_API APatrol_Controller : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
public:
		UPROPERTY(EditInstanceOnly, Category = "Patrol Waypoints")
		TArray<AActor*>PatrolPointsCPP;
	
};
