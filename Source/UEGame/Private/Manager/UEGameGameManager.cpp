// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/UEGameGameManager.h"
#include "Manager/UEGameTableManager.h"
#include "Framework/UEGamePlayerController.h"


UUEGameGameManager::UUEGameGameManager()
{
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
