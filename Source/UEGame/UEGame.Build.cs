// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEGame : ModuleRules
{
	public UEGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
