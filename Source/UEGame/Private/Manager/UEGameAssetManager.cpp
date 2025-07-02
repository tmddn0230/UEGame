// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/UEGameAssetManager.h"

void UUEGameAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}

UUEGameAssetManager& UUEGameAssetManager::Get()
{
	UUEGameAssetManager* This = Cast<UUEGameAssetManager>(GEngine->AssetManager);

	if (This)
	{
		return *This;
	}
	else
	{
		return *NewObject<UUEGameAssetManager>(); // never calls this
	}
}

void UUEGameAssetManager::Preload(FStreamableDelegate DelegateToCall)
{
	// 1) Gathering Load Asset ID List
	FPrimaryAssetType AssetType = FPrimaryAssetType(UUEGameDataAsset::StaticClass()->GetFName());
	TArray< FPrimaryAssetId> AssetsToLoad;
	GetPrimaryAssetIdList(AssetType, AssetsToLoad);
	TArray<FName> LoadBundles;

	// 2) Async Load
	LoadHandle = LoadPrimaryAssets(AssetsToLoad, LoadBundles);

	// 3) along Handle situation
	if (LoadHandle.IsValid())
	{
		if (!LoadHandle->HasLoadCompleted())
		{
			// Loding ¡æ Complete , Called Delegate
			LoadHandle->BindCompleteDelegate(DelegateToCall);
		}
		else
		{
			// Fin Load -> Call
			DelegateToCall.ExecuteIfBound();
		}
	}
	else
	{
		// Fail or Not Thing anymore loading asset -> call
		DelegateToCall.ExecuteIfBound();
	}
}

UUEGameDataAsset* UUEGameAssetManager::ForceLoad_ModeDefinition(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning)
{
	FSoftObjectPath ObjPath = GetPrimaryAssetPath(PrimaryAssetId);

	// This does a synchronous load and may hitch
	UUEGameDataAsset* obj = Cast<UUEGameDataAsset>(ObjPath.TryLoad());

	if (bLogWarning && obj == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to obj for identifier %s!"), *PrimaryAssetId.ToString());
	}

	return obj;
}

UUEGameDataAsset* UUEGameAssetManager::Load_ModeSetting()
{
	// *** for debug ******
	/*
	UE_LOG(LogTemp, Warning, TEXT("Using AssetManager class: %s"),
		*UAssetManager::Get().GetClass()->GetName());

	TArray<FPrimaryAssetId> IDs;
	GetPrimaryAssetIdList(FPrimaryAssetType(TEXT("UEGameDataAsset")), IDs);
	for (auto& ID : IDs)
	{
		UE_LOG(LogTemp, Log, TEXT("Found PrimaryAsset: Type=%s Name=%s"),
			*ID.PrimaryAssetType.ToString(),
			*ID.PrimaryAssetName.ToString());
	}
	*/

	FPrimaryAssetId AssetId = FPrimaryAssetId(FPrimaryAssetType(UUEGameDataAsset::StaticClass()->GetFName()), "UEGameDataAsset_Mode");
	return ForceLoad_ModeDefinition(AssetId, true);
}
