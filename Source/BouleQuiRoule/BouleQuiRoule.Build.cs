// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BouleQuiRoule : ModuleRules
{
	public BouleQuiRoule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
