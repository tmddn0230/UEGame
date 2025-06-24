// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/UEGame_UserWidget.h"
// Widget
#include "UI/UEGame_PageBase.h"
#include "UEGame_PrimaryLayout.generated.h"

UEGAME_API DECLARE_LOG_CATEGORY_EXTERN(LogPrimaryLayout, Log, All);

/**
 * 
 */
UCLASS()
class UEGAME_API UUEGame_PrimaryLayout : public UUEGame_UserWidget
{
	GENERATED_BODY()

	// Various
public:
	UPROPERTY(meta = (BindWidget))	USizeBox* Game_Layer;
	UPROPERTY(meta = (BindWidget))	USizeBox* Menu_Layer;
	UPROPERTY(meta = (BindWidget))	USizeBox* Popup_Layer;
	UPROPERTY()	TArray<UUEGame_PageBase*> Popup_Stack;


	// Fucntions

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;
public:
	virtual bool Initialize() override;
	virtual void BeginDestroy() override;


public:

	// UI Control
	UUEGame_PageBase* Open_Page(const FName& InName, bool InPopup, APlayerController* InPC, UUserWidget* InConnection);
	bool Close_Popup(UUEGame_PageBase* InWidget);

	UUEGame_PageBase* Inter_Open_Page(const FName& InName, TSubclassOf<UUserWidget> UserWidgetClass, APlayerController* InPC, UUserWidget* InConnection);
	UUEGame_PageBase* Inter_Open_Popup(const FName& InName, TSubclassOf<UUserWidget> UserWidgetClass, APlayerController* InPC, UUserWidget* InConnection);

private:
	void Inter_Change_PageWidget(UUserWidget* InWidget);
	void Inter_Add_PopupWidget(UUEGame_PageBase* InWidget);

};
