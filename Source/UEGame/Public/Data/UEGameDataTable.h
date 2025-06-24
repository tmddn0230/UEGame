// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "Common/UEGameCommon.h"

#include "UEGameDataTable.generated.h"

/**
 * Data Table Rows
 */

USTRUCT(BlueprintInternalUseOnly)
struct FUEGameRow_UI : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere) TSubclassOf<class UUserWidget> WidgetClass;
	UPROPERTY(EditAnywhere) FString						   Description;
};

USTRUCT(BlueprintInternalUseOnly)
struct FUEGame_MessageBoxButtonAction
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MessageBoxBtn")	EUEGame_MessageResult Result = EUEGame_MessageResult::Unknown;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MessageBoxBtn")	FText Text;
};

USTRUCT(BlueprintInternalUseOnly)
struct FUEGameTableRow_MessageBox : public FTableRowBase
{

	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl")	FText Header;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl")	FText Body;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl")	FString DebugText;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl")	TArray<FUEGame_MessageBoxButtonAction> ButtonArray;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl") UTexture2D* Texture_Normal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl") UTexture2D* Texture_Hover;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RtControl") UTexture2D* Texture_Cancel;

};


UCLASS()
class UEGAME_API UUEGameDataTable : public UDataTable
{
	GENERATED_BODY()
	
};
