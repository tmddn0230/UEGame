// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/UEGameGameManager.h"
#include "Manager/UEGameTableManager.h"
#include "Manager/UEGameAssetManager.h"
#include "Framework/UEGamePlayerController.h"
// Data
#include "Data/UEGameDataAsset.h"

// Log
DEFINE_LOG_CATEGORY(LogGameManager);


UUEGameGameManager::UUEGameGameManager()
{
}

void UUEGameGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Collection.InitializeDependency(UUEGameTableManager::StaticClass());

	Super::Initialize(Collection);

	if (GIsEditor) {
		bInitialized = true;
		IsInitialzied(); // 추후에 Play MODE 추가시 변동
	}
	else {
		UUEGameAssetManager& AssetManager = UUEGameAssetManager::Get();
		AssetManager.Preload(FStreamableDelegate::CreateUObject(this, &UUEGameGameManager::HandleLoadCompleted));
	}

}

void UUEGameGameManager::Deinitialize()
{
	Super::Deinitialize();
}

bool UUEGameGameManager::IsInitialzied()
{
	UE_LOG(LogGameManager, Log, TEXT("%d"), (int)bInitialized);

	if (!bInitialized)
		return false;

	if (!ModeDefinition) {
		ModeDefinition = UUEGameAssetManager::Get().Load_ModeSetting();
	}
	return ModeDefinition ? true : false;
}

AUEGamePlayerController* UUEGameGameManager::Get_LocalPlayerController()
{
	auto* pc = Cast<AUEGamePlayerController>(GetGameInstance()->GetFirstLocalPlayerController());
	return pc;
}

UUEGameTableManager* UUEGameGameManager::Get_TableManager()
{
	return GetGameInstance()->GetSubsystem<UUEGameTableManager>();
}

void UUEGameGameManager::HandleLoadCompleted()
{
	checkNoReentry();

	UAssetManager& AssetManager = UAssetManager::Get();
	FPrimaryAssetType AssetType = FPrimaryAssetType(UUEGameDataAsset::StaticClass()->GetFName());

	FPrimaryAssetId AssetId = FPrimaryAssetId(AssetType, "DA_ModeDatas");

	UObject* AssetPtr = nullptr;
	AssetPtr = AssetManager.GetPrimaryAssetObject(AssetId);

	ModeDefinition = Cast<UUEGameDataAsset>(AssetPtr);

	UE_LOG(LogGameManager, Log, TEXT("GameManager initialized"));

	OnInitialized_Delegate.Broadcast();

	//Initialize Manager
	bInitialized = true;

}
