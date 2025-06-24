// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UEGamePlayerController.generated.h"

class AUEGameFollowCam;
class AUEGameHUD;
class UUEGame_PageBase;
class UUEGame_PrimaryLayout;
/**
 * 
 */
UCLASS()
class UEGAME_API AUEGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	AUEGameFollowCam* FollowCam;


	AUEGameHUD* Get_HUD();

	TWeakObjectPtr<UUEGame_PrimaryLayout> Get_Primary_Layout();

	UUEGame_PageBase* Open_Popup(const FName& InName);
	UUEGame_PageBase* Open_Page(const FName& InName);
	bool Close_Popup(UUEGame_PageBase* InPage);
protected:
	virtual void BeginPlay() override;



};
