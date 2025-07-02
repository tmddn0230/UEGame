// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
// Data
#include "Data/UEGameDataAsset.h"
#include "UEGameAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class UEGAME_API UUEGameAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	TSharedPtr<FStreamableHandle> LoadHandle;


	// Functions
public:

	virtual void StartInitialLoading() override;


	/** Returns the current AssetManager object */
	static UUEGameAssetManager& Get();

	void Preload(FStreamableDelegate DelegateToCall);

	// Load Mode Setting Data
	UUEGameDataAsset* ForceLoad_ModeDefinition(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning);
	UUEGameDataAsset* Load_ModeSetting();


};
