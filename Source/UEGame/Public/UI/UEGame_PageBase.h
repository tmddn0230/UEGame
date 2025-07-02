// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UEGame_UserWidget.h"
#include "Components/SizeBox.h"
#include "UEGame_PageBase.generated.h"

class UUEGame_PageBase;

/**
 * 
 */
UCLASS()
class UEGAME_API UUEGame_PageBase : public UUEGame_UserWidget
{
	GENERATED_BODY()

public:

	// Function
	virtual void Post_OpenPage();
	//virtual void Close_Page();
	
	// BP Called
	UFUNCTION(BlueprintCallable)	UUEGame_PageBase* BPCall_Open_Popup(const FName& InName);
	UFUNCTION(BlueprintCallable)	bool			  BPCall_Close_Popup(UUEGame_PageBase* InPage);
	UFUNCTION(BlueprintCallable)	UUEGame_PageBase* BPCall_Open_Page(const FName& InName);
	
	virtual UUEGame_PageBase* Open_Popup(const FName& InName);
	virtual bool			  Close_Popup(UUEGame_PageBase* InPage);
	virtual UUEGame_PageBase* Open_Page(const FName& InName);
	
};
