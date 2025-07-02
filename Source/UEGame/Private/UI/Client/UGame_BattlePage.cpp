// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Client/UGame_BattlePage.h"
#include "UI/Parts/UEGame_ListViewObject.h"
#include "Framework/UEGamePlayerController.h"

void UUGame_BattlePage::Add_Item_ToListView(UObject* InObject)
{
	if (ListView_Var) {
		ListView_Var->AddItem(InObject);
	}
}

bool UUGame_BattlePage::Get_SelectedItem_InListView(FUGSkillInfo& OutInfo)
{
	if (!ListView_Var)
		return false;

	TArray<UObject*> OutSelectedItems;
	int32 selected = ListView_Var->GetSelectedItems(OutSelectedItems);
	if (selected == 0)
		return false;

	if (auto* selected_item = Cast< UUG_ListViewObject_SkillInfo>(OutSelectedItems[0])) {
		OutInfo = selected_item->Info_Skill;
		return true;
	}
	return false;
}

bool UUGame_BattlePage::Update_ListView(const TArray<FUGSkillInfo>& InInfo)
{
	if (ListView_Var == nullptr)
		return false;

	UUG_ListViewObject_SkillInfo* old_selected_item = Cast<UUG_ListViewObject_SkillInfo>(ListView_Var->GetSelectedItem());
	UUG_ListViewObject_SkillInfo* new_selected_item = nullptr;

	ListView_Var->ClearListItems();
	for (auto& it : InInfo) {
		auto* new_item = NewObject<UUG_ListViewObject_SkillInfo>();
		// gamestate 같은 곳에서 저장된 캐릭터 정보로 info 채우는 코드

		ListView_Var->AddItem(new_item);
	}
	if (new_selected_item) {
		ListView_Var->SetSelectedItem(new_selected_item);
	}

	return true;
}

void UUGame_BattlePage::Update_DeviceInfo_Cashed()
{
	if (auto* pc = Get_PlayerController()) {
		//auto& skill_array = pc->Get_SkillInfo(); // get SKILL INFO
		//Update_ListView(device_array);
	}
}

void UUGame_BattlePage::Update_DeviceInfo(APlayerController* InPlayerController, const TArray<FUGSkillInfo>& InDeviceArray)
{
	// Same Function with Update_DeviceInfo_Cashed, But need for Delegate when update trainingdata 

	if (auto* pc = Get_PlayerController()) {
		//auto& skill_array = pc->Get_SkillInfo(); // get SKILL INFO
		//Update_ListView(device_array);
	}
}
