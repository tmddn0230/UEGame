// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UEGame_PageBase.h"
// UE Component of Widget
#include "Components/ListView.h"
// Common
#include "Common/UEGameCommon.h"
#include "UGame_BattlePage.generated.h"

/**
 * 
 */
UCLASS()
class UEGAME_API UUGame_BattlePage : public UUEGame_PageBase
{
	GENERATED_BODY()
	
private:
	// List View 
	void Add_Item_ToListView(UObject* InObject);
	bool Get_SelectedItem_InListView(FUGSkillInfo& OutInfo);
	bool Update_ListView(const TArray<FUGSkillInfo>& InInfo);

public:
	UPROPERTY(meta = (BindWidget))	UListView* ListView_Var;


	// Active List View
	void Update_DeviceInfo_Cashed();
	void Update_DeviceInfo(APlayerController* InPlayerController, const TArray<FUGSkillInfo>& InDeviceArray);
};
