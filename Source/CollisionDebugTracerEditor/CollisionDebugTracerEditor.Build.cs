// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CollisionDebugTracerEditor : ModuleRules
{
	public CollisionDebugTracerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Blutility",
				"UnrealEd",
				"CollisionDebugTracer",
				"UMG",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
			}
		);
	}
}