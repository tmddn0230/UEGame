// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
//Common
#include "Common/UEGameCommon.h"
#include "UEGameGameManager.generated.h"

// Log
UEGAME_API DECLARE_LOG_CATEGORY_EXTERN(LogGameManager, Log, All);

// Framework
class AUEGamePlayerController;
class AUEGamePlayerState;

// Manager
class UUEGameTableManager;

// Data
class UUEGameDataAsset;

// Delegate
DECLARE_MULTICAST_DELEGATE(FOnInitialized_Delegate)
/**
 * 
 */
UCLASS()
class UEGAME_API UUEGameGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	FOnInitialized_Delegate OnInitialized_Delegate;

	bool bInitialized = false;

	TArray<IConsoleObject*> AuditCmds;

	EUEGame_GameFlow Current_GameMode = EUEGame_GameFlow::E_None;

	EUEGame_PlayType Play_Type		  = EUEGame_PlayType::E_None;
	EUEGame_PlayType Start_Play_Type  = EUEGame_PlayType::E_None;

	TObjectPtr<UUEGameDataAsset> ModeDefinition;

public:
	UUEGameGameManager();

	// Main Flow
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure) bool IsInitialzied();

	// Costom GetSet
	EUEGame_GameFlow		 Get_Current_GameMode() { return Current_GameMode; }
	EUEGame_PlayType		 Get_Play_Type()		{ return Play_Type; }
	EUEGame_PlayType		 Get_Start_Play_Type()  { return Start_Play_Type; }
	AUEGamePlayerController* Get_LocalPlayerController();
	UUEGameTableManager*	 Get_TableManager();

	UFUNCTION()
	void HandleLoadCompleted();
};
