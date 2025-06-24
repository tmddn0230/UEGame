// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

//Data
#include "Data/UEGameDataTable.h"

#include "UEGameTableManager.generated.h"

/**
 * 
 */
UCLASS()
class UEGAME_API UUEGameTableManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	UPROPERTY()	UDataTable* ServerWidget_Table;
	UPROPERTY()	UDataTable* ClientWidget_Table;
	UPROPERTY()	UDataTable* MessageBox_Table;
	

public:
	/*
	Functions
	*/
	// Main Flow'
	UUEGameTableManager();

	// Custom Get Set
	FUEGameRow_UI*				Get_UI(UDataTable* data_table, const FName& row_name);
	FUEGameTableRow_MessageBox* Get_MessageBox(const FName& row_name);

	TSubclassOf<UUserWidget>	Get_UIWidget(int number, const FName& row_name);

};
