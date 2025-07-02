// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UEGame_PageBase.h"
#include "Framework/UEGamePlayerController.h"



void UUEGame_PageBase::Post_OpenPage()
{
	// 페이지를 연 다음 처리할 코드 
	// ex > UMG Animation 
	//      Sounds 
}

UUEGame_PageBase* UUEGame_PageBase::BPCall_Open_Popup(const FName& InName)
{
	return Open_Popup(InName);
}

bool UUEGame_PageBase::BPCall_Close_Popup(UUEGame_PageBase* InPage)
{
	return Close_Popup(InPage);
}

UUEGame_PageBase* UUEGame_PageBase::BPCall_Open_Page(const FName& InName)
{
	return Open_Page(InName);
}

UUEGame_PageBase* UUEGame_PageBase::Open_Popup(const FName& InName)
{
	if (auto* pc = Get_PlayerController()) {
		return pc->Open_Popup(InName);
	}
	return nullptr;
}

bool UUEGame_PageBase::Close_Popup(UUEGame_PageBase* InPage)
{
	if (auto* pc = Get_PlayerController()) {
		return pc->Close_Popup(InPage);
	}
	return false;
}

UUEGame_PageBase* UUEGame_PageBase::Open_Page(const FName& InName)
{
	if (auto* pc = Get_PlayerController()) {
		return pc->Open_Page(InName);
	}
	return nullptr;
}
