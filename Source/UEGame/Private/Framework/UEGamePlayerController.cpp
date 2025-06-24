// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/UEGamePlayerController.h"
// UE
#include "Kismet/GameplayStatics.h"
// Framework
#include "Framework/UEGameFollowCam.h"
#include "Framework/UEGameHUD.h"
// UI
#include "UI/UEGame_PageBase.h"
#include "UI/UEGame_PrimaryLayout.h"

void AUEGamePlayerController::BeginPlay()
{
    Super::BeginPlay();

    // 에디터 할당이 안 되어 있으면 GetAllActorsOfClass 로 검색
    if (!FollowCam)
    {
        TArray<AActor*> Found;
        UGameplayStatics::GetAllActorsOfClass(this, AUEGameFollowCam::StaticClass(), Found);
        if (Found.Num() > 0)
        {
            FollowCam = Cast<AUEGameFollowCam>(Found[0]);
        }
    }

    if (FollowCam)
    {
        // 뷰타겟만 바꾼다
        bAutoManageActiveCameraTarget = false;
        SetViewTargetWithBlend(FollowCam, 0.f);
    }



    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
}

AUEGameHUD* AUEGamePlayerController::Get_HUD()
{
    auto* res = Cast<AUEGameHUD>(GetHUD());
    return res;
}

TWeakObjectPtr<UUEGame_PrimaryLayout> AUEGamePlayerController::Get_Primary_Layout()
{
	return TWeakObjectPtr<UUEGame_PrimaryLayout>();
}

UUEGame_PageBase* AUEGamePlayerController::Open_Popup(const FName& InName)
{
	if (auto* hud = Get_HUD()) {
		return hud->Open_Page(InName, true);
	}
	else {
		TWeakObjectPtr<UUEGame_PrimaryLayout> primary_layout = Get_Primary_Layout();
		if (primary_layout.IsValid()) {
			primary_layout.Get()->Open_Page(InName, true, this, nullptr);
		}
	}
	return nullptr;
}

UUEGame_PageBase* AUEGamePlayerController::Open_Page(const FName& InName)
{
	if (auto* hud = Get_HUD()) {
		return hud->Open_Page(InName, false);
	}
	else {
		TWeakObjectPtr<UUEGame_PrimaryLayout> primary_layout = Get_Primary_Layout();
		if (primary_layout.IsValid()) {
			primary_layout.Get()->Open_Page(InName, false, this, nullptr);
		}
	}
	return nullptr;
}

bool AUEGamePlayerController::Close_Popup(UUEGame_PageBase* InPage)
{
	if (auto* hud = Get_HUD()) {
		return hud->Close_Popup(InPage);
	}
	else {
		TWeakObjectPtr<UUEGame_PrimaryLayout> primary_layout = Get_Primary_Layout();
		if (primary_layout.IsValid()) {
			primary_layout.Get()->Close_Popup(InPage);
		}
	}
	return false;
}