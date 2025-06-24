// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * Commons
 */

UENUM(BlueprintType)
enum class EUEGame_PlayType : uint8
{
	E_None		UMETA(DisplayName = "None"),
	E_Single	UMETA(DisplayName = "Single"),        // Single
	E_Listen	UMETA(DisplayName = "Listen"),        // Listen
	E_Dedicate	UMETA(DisplayName = "E_Dedicate"),    // Dedicate
};


enum class EUEGame_GameFlow
{
	E_None,
	E_Menu,           // 
	E_Lobby,          // 
	E_Playing,     // 
	E_Result       //
};

/** Possible results from a dialog */
UENUM(BlueprintType)
enum class EUEGame_MessageResult : uint8
{
	/** The "yes" button was pressed */
	Confirmed,
	/** The "no" button was pressed */
	Declined,
	/** The "ignore/cancel" button was pressed */
	Cancelled,
	/** The dialog was explicitly killed (no user input) */
	Killed,
	Unknown UMETA(Hidden)
};

DECLARE_DELEGATE_OneParam(FUEGameDele_MessagResult, EUEGame_MessageResult /* Result */);


class UEGAME_API UEGameCommon
{
public:
	UEGameCommon();
	~UEGameCommon();
};
