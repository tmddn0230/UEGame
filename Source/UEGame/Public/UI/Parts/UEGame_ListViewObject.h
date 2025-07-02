// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Common/UEGameCommon.h"

#include "UEGame_ListViewObject.generated.h"

/**
 * 
 */
UCLASS()
class UEGAME_API UUG_ListViewObject_SkillInfo: public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FUGSkillInfo Info_Skill;
	
	void FillData_SkillInfo(const FUGSkillInfo& InSkillData);

};


