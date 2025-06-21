// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/UEGameFollowCam.h"
// UE
#include "Kismet/GameplayStatics.h"
// Framework
#include "Framework/UEGameCharacter.h"
// Custom
#include "Custom/UEGameTower.h"

AUEGameFollowCam::AUEGameFollowCam()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AUEGameFollowCam::BeginPlay()
{
	Super::BeginPlay();

	// if In MultiGame, This Function Called OnRep_, But In Single(now) Called here
	InitializeCamera();
}

void AUEGameFollowCam::InitializeCamera()
{
	// 생성 순서 : Tower -> Character -> Camera
	// Tower Enter
	AActor* found = UGameplayStatics::GetActorOfClass(GetWorld(), AUEGameTower::StaticClass());
	if (found != nullptr)
	{
		TowerActor = Cast<AUEGameTower>(found);
	}

	// Character Enter
	MyPC = UGameplayStatics::GetPlayerController(this, 0);
	if (MyPC != nullptr)
	{
		TargetCharacter = Cast<AUEGameCharacter>(MyPC->GetPawn());
	}
}

void AUEGameFollowCam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!TargetCharacter || !TowerActor) return;

	// 1) Calculate Location
	FVector CharLoc = TargetCharacter->GetActorLocation();
	FVector TowLoc =  TowerActor->GetActorLocation();
	FVector DirToChar = (CharLoc - TowLoc).GetSafeNormal();
	FVector CamPos = CharLoc + DirToChar * DistanceFromChar + FVector(0, 0, HeightOffset);
	SetActorLocation(CamPos);

	// 2) Look at Tower
	FRotator CamRot = (TowLoc - CamPos).Rotation();
	SetActorRotation(CamRot);
}