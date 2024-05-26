// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WorldAudioDataSystem : ModuleRules
{
	public WorldAudioDataSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
        { 
            "Core", 
            "Soundscape",
            "PointCloud",
			"DeveloperSettings",
			"GameplayTags",
			"MassEntity",
			"MassSpawner",
			"StructUtils",
			"AudioModulation",
			"Crossfader",
        } );
		
		PrivateDependencyModuleNames.AddRange(new string[]
        { 
            "CoreUObject",
            "Engine",
			"Slate",
			"SlateCore",
			"MassCommon",
			"MassTraffic",
			"MassCrowd",
			"MassMovement",
			"MassLOD",
			"MassRepresentation",
			"MetasoundEngine",
			"AudioMixer",
			"MassNavigation",
			"AudioExtensions" 
        } );

		DynamicallyLoadedModuleNames.AddRange(new string[] { });

		// Because of UEdGraph's existence in the Engine Module & being the parent class of MetasoundEditorGraph (referenced by UMetaSound... types),
        // editor class definitions must be loaded prior to the WorldDataGameplayActor to ensure references are properly loaded.
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "MetasoundEditor" });
		}
	}
}
