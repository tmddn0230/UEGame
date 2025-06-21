// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/UEGamePlayerController.h"
// UE
#include "Kismet/GameplayStatics.h"
// Framework
#include "Framework/UEGameFollowCam.h"

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
        bAutoManageActiveCameraTarget = false;
        SetViewTargetWithBlend(FollowCam, 0.f);
    }
}
