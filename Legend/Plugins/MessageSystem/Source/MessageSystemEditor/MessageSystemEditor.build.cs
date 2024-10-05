using UnrealBuildTool;
 
public class MessageSystemEditor : ModuleRules
{
	public MessageSystemEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd", "MessageSystem", "AssetTools", "Slate" });
 
		PublicIncludePaths.AddRange(new string[] {"MessageSystemEditor/Public", "MessageSystem/Public"});
		PrivateIncludePaths.AddRange(new string[] {"MessageSystemEditor/Private"});
	}
}