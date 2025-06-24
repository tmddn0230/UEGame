// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

// Common
#include "Common/UEGameCommon.h"

#include "UEGameHUD.generated.h"

// Framework
class AUEGamePlayerController;

// Manager
class UUEGameGameManager;
class UUEGameTableManager;

// Widget
class UUEGame_PageBase;
class UUEGame_PrimaryLayout;

UEGAME_API DECLARE_LOG_CATEGORY_EXTERN(LogUGHUD, Log, All);

/**
 * 
 */
UCLASS()
class UEGAME_API AUEGameHUD : public AHUD
{
	GENERATED_BODY()

	// Various
private:
	TWeakObjectPtr<UUEGame_PrimaryLayout> Primary_Layout;

	// Function
public:

	// Custom Get Set
	// Get
	AUEGamePlayerController* Get_PlayerController();
	UUEGameGameManager*		 Get_GameManager();
	UUEGameTableManager*	 Get_TableManager();

	// UI Control
	bool Init_Primary_Layer();
	void Open_HUD_Widget();
	UUEGame_PageBase* Open_Page(const FName& InName, bool InPopup);
	bool Close_Popup(UUEGame_PageBase* InPage);
	void Show_MessageBox(const FName& InNmae, FUEGameDele_MessagResult ResultCallback);

	// Main Flow
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
};
