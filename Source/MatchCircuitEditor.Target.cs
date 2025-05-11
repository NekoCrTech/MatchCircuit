// Developed by Neko

using UnrealBuildTool;
using System.Collections.Generic;

public class MatchCircuitEditorTarget : TargetRules
{
	public MatchCircuitEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "MatchCircuit" } );
	}
}
