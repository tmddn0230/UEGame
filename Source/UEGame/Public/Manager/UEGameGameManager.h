// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
//Common
#include "Common/UEGameCommon.h"
#include "UEGameGameManager.generated.h"

// Framework
class AUEGamePlayerController;
class AUEGamePlayerState;

// Manager
class UUEGameTableManager;

/**
 * 
 */
UCLASS()
class UEGAME_API UUEGameGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:


	TArray<IConsoleObject*> AuditCmds;

	EUEGame_GameFlow Current_GameMode = EUEGame_GameFlow::E_None;

	EUEGame_PlayType Play_Type		  = EUEGame_PlayType::E_None;
	EUEGame_PlayType Start_Play_Type  = EUEGame_PlayType::E_None;

public:
	UUEGameGameManager();

	// Costom GetSet
	EUEGame_GameFlow		 Get_Current_GameMode() { return Current_GameMode; }
	EUEGame_PlayType		 Get_Play_Type()		{ return Play_Type; }
	EUEGame_PlayType		 Get_Start_Play_Type()  { return Start_Play_Type; }
	AUEGamePlayerController* Get_LocalPlayerController();
	UUEGameTableManager*	 Get_TableManager();
};
