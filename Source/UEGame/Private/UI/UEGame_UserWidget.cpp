// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UEGame_UserWidget.h"
// Framework
#include "Framework/UEGamePlayerController.h"
#include "Framework/UEGameGameMode.h"

// Manager
#include "Manager/UEGameGameManager.h"


void UUEGame_UserWidget::Begin_Play()
{

}

UUEGameGameManager* UUEGame_UserWidget::GetGameManager()
{
	if (auto* gi = GetGameInstance())
		return gi->GetSubsystem<UUEGameGameManager>();

	return nullptr;
}

AUEGamePlayerController* UUEGame_UserWidget::Get_PlayerController()
{
	return Cast<AUEGamePlayerController>(GetOwningPlayer());
}

AUEGameGameMode* UUEGame_UserWidget::Get_GameMode()
{
	UWorld* world = GetWorld();
	check(world);
	return Cast<AUEGameGameMode>(GetWorld()->GetAuthGameMode());
}

AUEGameHUD* UUEGame_UserWidget::Get_HUD()
{
	if (auto* pc = Get_PlayerController()) {
		return pc->Get_HUD();
	}
	return nullptr;
}
