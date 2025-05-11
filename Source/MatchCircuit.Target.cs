// Developed by Neko

using UnrealBuildTool;
using System.Collections.Generic;

public class MatchCircuitTarget : TargetRules
{
	public MatchCircuitTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "MatchCircuit" } );
	}
}
