// Snake Game, Copyright LifeEXE. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GSnakeTarget : TargetRules
{
	public GSnakeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "GSnake" } );
	}
}
