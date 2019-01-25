// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class Ability;
class AActor;

class NEON_API MoveAbility : Ability
{
public:
	MoveAbility();
	~MoveAbility();
	virtual void Execute(AActor*, AActor*);
};
