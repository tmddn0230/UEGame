// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UEGame_PrimaryLayout.h"
//Framework
#include "Framework/UEGamePlayerController.h"
#include "Framework/UEGameGameMode.h"

// Manager
#include "Manager/UEGameGameManager.h"
#include "Manager/UEGameTableManager.h"

// Data
#include "Data/UEGameDataTable.h"

// Widget
#include "UI/UEGame_PageBase.h"

DEFINE_LOG_CATEGORY(LogPrimaryLayout);

void UUEGame_PrimaryLayout::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UUEGame_PrimaryLayout::NativeDestruct()
{
	Super::NativeDestruct();
}

bool UUEGame_PrimaryLayout::Initialize()
{
	bool res = Super::Initialize();
	return res;
}

void UUEGame_PrimaryLayout::BeginDestroy()
{
	Super::BeginDestroy();
}

UUEGame_PageBase* UUEGame_PrimaryLayout::Open_Page(const FName& InName, bool InPopup, APlayerController* InPC, UUserWidget* InConnection)
{
	UE_LOG(LogPrimaryLayout, Log, TEXT("Open_PopupUI: %s"), *InName.ToString());

	if (AUEGamePlayerController* PC = Cast<AUEGamePlayerController>(InPC)) {
		if (auto* mgr = GetGameManager()) {

			if (auto* table = mgr->Get_TableManager()) {
				if (FUEGameRow_UI* table_row = table->Get_UI(table->ClientWidget_Table ,InName)) { // Client 동작, 추후 Type 별 동작 구분
					if (table_row && table_row->WidgetClass) {
						if (InPopup)
							return Inter_Open_Popup(InName, table_row->WidgetClass, InPC, InConnection);
						else
							return Inter_Open_Page(InName, table_row->WidgetClass, InPC, InConnection);
					}
				}
			}
		}
	}
	return nullptr;
}

bool UUEGame_PrimaryLayout::Close_Popup(UUEGame_PageBase* InWidget)
{
	bool res = false;

	if (Popup_Stack.Num() == 0) return false;

	auto* last = Popup_Stack.Last();
	if (last) {
		if (last == InWidget) {
			last->RemoveFromParent();
			Popup_Stack.Pop();
		}
		else {
			//check(0);
			return false;
		}
	}
	return res;
}

UUEGame_PageBase* UUEGame_PrimaryLayout::Inter_Open_Page(const FName& InName, TSubclassOf<UUserWidget> UserWidgetClass, APlayerController* InPC, UUserWidget* InConnection)
{
	if (UUserWidget* widget = CreateWidget<UUserWidget>(InPC, UserWidgetClass)) {
		if (auto UGWidget = Cast<UUEGame_PageBase>(widget)) {
			if (InConnection) {
				UGWidget->Widget_Name = InName;
				UGWidget->Connection_Widget = InConnection;
			}
			Inter_Change_PageWidget(widget);
			return UGWidget;
		}
	}
	return nullptr;
}

UUEGame_PageBase* UUEGame_PrimaryLayout::Inter_Open_Popup(const FName& InName, TSubclassOf<UUserWidget> UserWidgetClass, APlayerController* InPC, UUserWidget* InConnection)
{
	if (UUserWidget* widget = CreateWidget<UUserWidget>(InPC, UserWidgetClass)) {
		if (auto UGWidget = Cast<UUEGame_PageBase>(widget)) {
			if (InConnection) {
				UGWidget->Widget_Name = InName;
				UGWidget->Connection_Widget = InConnection;
			}
			Inter_Add_PopupWidget(UGWidget);
			return UGWidget;
		}
	}
	return nullptr;
}

void UUEGame_PrimaryLayout::Inter_Change_PageWidget(UUserWidget* InWidget)
{
	if (Game_Layer && InWidget) {
		Game_Layer->ClearChildren();
		Game_Layer->AddChild(InWidget);
	}
}

void UUEGame_PrimaryLayout::Inter_Add_PopupWidget(UUEGame_PageBase* InWidget)
{
	if (InWidget && Popup_Layer) {
		Popup_Stack.Push(InWidget);
		Popup_Layer->AddChild(InWidget);
	}
}
