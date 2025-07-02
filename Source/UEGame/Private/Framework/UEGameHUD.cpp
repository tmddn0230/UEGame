// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/UEGameHUD.h"
#include "Framework/UEGamePlayerController.h"
// Manager
#include "Manager/UEGameGameManager.h"
#include "Manager/UEGameTableManager.h"
// UI
#include "UI/UEGame_PrimaryLayout.h"
#include "UI/UEGame_PageBase.h"
// Data
#include "Data/UEGameDataAsset.h"


DEFINE_LOG_CATEGORY(LogUGHUD);


AUEGamePlayerController* AUEGameHUD::Get_PlayerController()
{
	return Cast<AUEGamePlayerController>(GetOwningPlayerController());
}

UUEGameGameManager* AUEGameHUD::Get_GameManager()
{
	if (auto* gi = GetGameInstance())
		return gi->GetSubsystem<UUEGameGameManager>();

	return nullptr;
}

UUEGameTableManager* AUEGameHUD::Get_TableManager()
{
	if (auto* gi = GetGameInstance())
		return gi->GetSubsystem<UUEGameTableManager>();

	return nullptr;
}

bool AUEGameHUD::Init_Primary_Layer()
{
	if (Primary_Layout.Get())
		return true;
	if (auto* mgr = Get_GameManager()) {
		if (auto* table = Get_TableManager()) {
			if (auto widget_class = table->Get_UIWidget(0, "PrimaryLayer")) { // Client
				if (UUEGame_PrimaryLayout* widget = CreateWidget<UUEGame_PrimaryLayout>(GetOwningPlayerController(), widget_class)) {
					widget->AddToViewport();
					Primary_Layout = widget;
					return true;
				}
			}
		}
	}
	return false;
}

void AUEGameHUD::Open_HUD_Widget()
{
	Init_Primary_Layer();

	UUEGame_PageBase* res = nullptr;
	auto* pc = GetOwningPlayerController();
	if (auto* mgr = Get_GameManager()) {

		if (auto ModeDefinition = mgr->ModeDefinition.Get()) {
			auto play_type = mgr->Get_Play_Type();
		
			auto mode = ModeDefinition->Get_Mode(play_type);
		
			if (mode.UI_Name != NAME_None) {
				res = Open_Page(mode.UI_Name, false);
				if (res) {
					res->Post_OpenPage();
				}
				else {
					UE_LOG(LogUGHUD, Warning, TEXT("Widget is missing or UUEGame_PageBase is not a parent class"));
				}
			}
			GetOwningPlayerController()->SetShowMouseCursor(mode.ShowMouseCursor);
		}
	}
}

UUEGame_PageBase* AUEGameHUD::Open_Page(const FName& InName, bool InPopup)
{
	if (Primary_Layout.Get()) {
		return Primary_Layout.Get()->Open_Page(InName, InPopup, Get_PlayerController(), nullptr);
	}
	return nullptr;
}

bool AUEGameHUD::Close_Popup(UUEGame_PageBase* InPage)
{
	if (Primary_Layout.Get()) {
		return Primary_Layout.Get()->Close_Popup(InPage);
	}
	return false;
}

void AUEGameHUD::Show_MessageBox(const FName& InNmae, FUEGameDele_MessagResult ResultCallback)
{
	if (auto* gi = GetGameInstance()) {

		if (auto* mgr = gi->GetSubsystem<UUEGameTableManager>()) {
			if (auto* row = mgr->Get_MessageBox(InNmae)) {
				
				//if (UUEGame_MessageBox* page = Cast<UUEGame_MessageBox>(Open_Page("ConfirmPopup", true))) {
				//	page->Setup_Dialog(row, ResultCallback);
				//}
			}
		}
	}
}

void AUEGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (auto* player = Cast<ULocalPlayer>(GetNetOwningPlayer()))
	{
		this->Open_HUD_Widget();
	}
}

void AUEGameHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
