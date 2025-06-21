// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Framework/UEGamePlayerController.h"
#include "UEGameFollowCam.generated.h"


class AUEGameCharacter;
class APlayerController;
class AUEGameTower;
/**
 * 
 */
UCLASS()
class UEGAME_API AUEGameFollowCam : public ACameraActor
{
	GENERATED_BODY()
	
public:


	// RepNotify 옵션으로 TargetCharacter가 복제될 때 OnRep_TargetCharacter() 호출
	// UPROPERTY(ReplicatedUsing = OnRep_TargetCharacter)
	UPROPERTY(EditAnywhere) AUEGameCharacter* TargetCharacter;			// 따라 다닐 캐릭터
	// RepNotify 옵션으로 TowerActor가 복제될 때 OnRep_TowerActor() 호출
	//UPROPERTY(ReplicatedUsing = OnRep_TowerActor)
	UPROPERTY(EditAnywhere) AUEGameTower*	TowerActor;					// 빌보드 할 타워
	UPROPERTY(EditAnywhere) float   DistanceFromChar = 600.f;   // 캐릭터와의 거리 
	UPROPERTY(EditAnywhere) float   HeightOffset = 200.f;		// 높이

	// 클라이언트에서 안전하게 캐릭터 인스턴스를 가져오기 위함
	APlayerController* MyPC;

public:
	AUEGameFollowCam();

	// 카메라 위치·회전 초기화 로직
	void InitializeCamera();

	virtual void Tick(float DeltaTime) override;



	// 추후 Rep 작업시
	// Replication 세팅
	//virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// RepNotify 함수
	//UFUNCTION()
	//void OnRep_TowerActor();

	//UFUNCTION()
	//void OnRep_TargetCharacter();

protected:
	virtual void BeginPlay() override;
};
