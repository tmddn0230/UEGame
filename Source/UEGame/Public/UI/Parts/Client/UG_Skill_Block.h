// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UEGame_UserWidget.h"

// widget Comp
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Math/Color.h"

#include "UG_Skill_Block.generated.h"

/**
 * 
 */
UCLASS()
class UEGAME_API UUG_Skill_Block : public UUEGame_UserWidget
{
	GENERATED_BODY()


protected:
	virtual void NativeOnInitialized() override;


public:
	// Basic
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UTextBlock* Text_InputKey;			// 키보드 입력 알림 w,a,s,d 등 
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UImage*	   Img_CharacterThumbnail;  // 스킬 사용 캐릭터 썸네일 
	// Execute Button
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget)) UButton*	   Active_Btn;				// 스킬 사용 버튼

	UPROPERTY(BlueprintReadOnly) class UUG_ListViewObject_SkillInfo* SkillInfoObj;

	UFUNCTION(BlueprintCallable)
	void OnClicked_Active_Btn();



	void FillBlocks(class UUG_ListViewObject_SkillInfo* IndeviceInfoObj);

};
