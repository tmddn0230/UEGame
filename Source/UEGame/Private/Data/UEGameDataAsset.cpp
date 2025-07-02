// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/UEGameDataAsset.h"

FName UUEGameDataAsset::Get_UI(EUEGame_PlayType InPlayType)
{
	switch (InPlayType)
	{
	case EUEGame_PlayType::E_Single:
		return ClientMode.UI_Name;
	case EUEGame_PlayType::E_Listen:
		return ServerMode.UI_Name;
	case EUEGame_PlayType::E_Dedicate:
		return ServerMode.UI_Name;

	default:
		return NAME_None;
	}
}

const FUEGameModeInfo& UUEGameDataAsset::Get_Mode(EUEGame_PlayType InPlayType)
{
	switch (InPlayType)
	{
	case EUEGame_PlayType::E_Single:
		return ClientMode;
	case EUEGame_PlayType::E_Listen:
		return ServerMode;
	case EUEGame_PlayType::E_Dedicate:
		return ServerMode;
	default:
		return ClientMode;
	}
}
