// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/UEGameTableManager.h"
// UE
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Table Load Macro
#define UGDEF_TABLE_PATH "/Game/UEGame/Table/"
#define UGDEF_LOAD_TABLE(table_value, table_name) \
static ConstructorHelpers::FObjectFinder<UDataTable>Object_##table_value(TEXT(UGDEF_TABLE_PATH#table_name"."#table_name)); \
if (Object_##table_value.Succeeded() && Object_##table_value.Object != nullptr) { \
		table_value = Object_##table_value.Object;	\
}


UUEGameTableManager::UUEGameTableManager()
{
	UGDEF_LOAD_TABLE(ServerWidget_Table, DT_ServerUI);
	UGDEF_LOAD_TABLE(ClientWidget_Table, DT_MainUI);
	UGDEF_LOAD_TABLE(MessageBox_Table,   DT_MessageBox);
}


FUEGameRow_UI* UUEGameTableManager::Get_UI(UDataTable* data_table, const FName& row_name)
{
	FUEGameRow_UI* OutRow = data_table->FindRow<FUEGameRow_UI>(row_name, "");
	return OutRow;
}

FUEGameTableRow_MessageBox* UUEGameTableManager::Get_MessageBox(const FName& row_name)
{
	FUEGameTableRow_MessageBox* OutRow;
	OutRow = MessageBox_Table->FindRow<FUEGameTableRow_MessageBox>(row_name, "");
	return OutRow;
}

TSubclassOf<UUserWidget> UUEGameTableManager::Get_UIWidget(int number, const FName& row_name)
{
	switch (number)
	{
		// Client
	case 0:
		if (FUEGameRow_UI* table_row = Get_UI(ClientWidget_Table, row_name)) {
			return table_row->WidgetClass;
		}
		break;
		// Server
	case 1:
		if (FUEGameRow_UI* table_row = Get_UI(ServerWidget_Table, row_name)) {
			return table_row->WidgetClass;
		}
		break;
	}
	return nullptr;
}
