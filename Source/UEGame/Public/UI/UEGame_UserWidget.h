// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UEGame_UserWidget.generated.h"

// ¸ÅÅ©·Î
#define UGDEF_UI_EVENT_BINDING_CLICKED( p_value, p_delegate )\
if(p_value && !p_value->OnClicked.IsBound() ) p_value->OnClicked.AddDynamic(this, &p_delegate);

class UUEGameGameManager;
class AUEGamePlayerController;
class AUEGameHUD;
class AUEGameGameMode;

/**
 * 
 */
UCLASS()
class UEGAME_API UUEGame_UserWidget : public UUserWidget
{
	GENERATED_BODY()

	// Various
public:
	TWeakObjectPtr<UUserWidget> Connection_Widget;
	FName Widget_Name = "";


	// Functions
public:
	// Main Flow
	virtual void Begin_Play(); // use virtual only

	// Custom Get Set
// Get
	UFUNCTION(BlueprintCallable)
	UUEGameGameManager*		 GetGameManager();
	UFUNCTION(BlueprintCallable)
	AUEGamePlayerController* Get_PlayerController();
	UFUNCTION(BlueprintCallable)
	AUEGameGameMode*		 Get_GameMode();
	UFUNCTION(BlueprintCallable)
	AUEGameHUD*			     Get_HUD();
};
