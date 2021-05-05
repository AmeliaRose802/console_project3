// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class TheGreatEasterHeist : ModuleRules
{
	public TheGreatEasterHeist(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "GameplayTasks", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
