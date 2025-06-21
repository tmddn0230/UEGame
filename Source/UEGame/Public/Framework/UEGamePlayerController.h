// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UEGamePlayerController.generated.h"

class AUEGameFollowCam;
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


protected:
	virtual void BeginPlay() override;



};
