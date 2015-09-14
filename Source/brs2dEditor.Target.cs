// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class brs2dEditorTarget : TargetRules
{
	public brs2dEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "brs2d" } );
	}
}
