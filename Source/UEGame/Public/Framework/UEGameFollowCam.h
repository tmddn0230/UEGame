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


	// RepNotify �ɼ����� TargetCharacter�� ������ �� OnRep_TargetCharacter() ȣ��
	// UPROPERTY(ReplicatedUsing = OnRep_TargetCharacter)
	UPROPERTY(EditAnywhere) AUEGameCharacter* TargetCharacter;			// ���� �ٴ� ĳ����
	// RepNotify �ɼ����� TowerActor�� ������ �� OnRep_TowerActor() ȣ��
	//UPROPERTY(ReplicatedUsing = OnRep_TowerActor)
	UPROPERTY(EditAnywhere) AUEGameTower*	TowerActor;					// ������ �� Ÿ��
	UPROPERTY(EditAnywhere) float   DistanceFromChar = 600.f;   // ĳ���Ϳ��� �Ÿ� 
	UPROPERTY(EditAnywhere) float   HeightOffset = 200.f;		// ����

	// Ŭ���̾�Ʈ���� �����ϰ� ĳ���� �ν��Ͻ��� �������� ����
	APlayerController* MyPC;

public:
	AUEGameFollowCam();

	// ī�޶� ��ġ��ȸ�� �ʱ�ȭ ����
	void InitializeCamera();

	virtual void Tick(float DeltaTime) override;



	// ���� Rep �۾���
	// Replication ����
	//virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// RepNotify �Լ�
	//UFUNCTION()
	//void OnRep_TowerActor();

	//UFUNCTION()
	//void OnRep_TargetCharacter();

protected:
	virtual void BeginPlay() override;
};
