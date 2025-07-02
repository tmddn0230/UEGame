// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
// Common
#include "Common/UEGameCommon.h"
#include "UEGameDataAsset.generated.h"

/**
 * 
 */

USTRUCT()
struct FUEGameModeInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FName UI_Name;

	UPROPERTY(EditAnywhere)
	uint8 ShowMouseCursor : 1;

	FUEGameModeInfo() :UI_Name(NAME_None), ShowMouseCursor(false)
	{}
};

UCLASS()
class UEGAME_API UUEGameDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FName StartUI_Server;

	UPROPERTY(EditAnywhere)
	FName StartUI_Client;


	UPROPERTY(EditAnywhere)
	FUEGameModeInfo ClientMode;

	UPROPERTY(EditAnywhere)
	FUEGameModeInfo ServerMode;

public:
	FName Get_UI(EUEGame_PlayType InPlayType);
	const FUEGameModeInfo& Get_Mode(EUEGame_PlayType InPlayType);

};
