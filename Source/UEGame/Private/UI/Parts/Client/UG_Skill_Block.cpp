// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Parts/Client/UG_Skill_Block.h"
#include "Common/UEGameCommon.h"

// ListViewObject <- Need for Data Synchronization between List and Block
#include "UI/Parts/UEGame_ListViewObject.h"


// Framework
#include "Framework/UEGamePlayerController.h"



void UUG_Skill_Block::NativeOnInitialized()
{
	// Button Binding
	Active_Btn->OnClicked.AddDynamic(this, &UUG_Skill_Block::OnClicked_Active_Btn);
}

void UUG_Skill_Block::OnClicked_Active_Btn()
{
	if (auto* pc = Get_PlayerController()) {
		if (SkillInfoObj->Info_Skill.CharacterName != "") {
			// 스킬 실행 캐릭터 이름에 따라?
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Not Found Skill Info."));
		}
	}
}

void UUG_Skill_Block::FillBlocks(UUG_ListViewObject_SkillInfo* IndeviceInfoObj)
{
}
