#include "MessageSystemEditor.h"
#include "MessageManager.h"
#include "MessageAssetActions.h"
#include "MessageDataTableActions.h"

#if WITH_EDITOR
// SettingsモジュールはEditor用のため、Packaging時には参照しないようにしておく
#include "ISettingsModule.h"
#endif
#include "AssetToolsModule.h"

DEFINE_LOG_CATEGORY(MessageSystemEditor);

#define LOCTEXT_NAMESPACE "FMessageSystemEditor"

void FMessageSystemEditor::StartupModule() {
#if WITH_EDITOR

	ISettingsModule* SettingModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingModule != nullptr) {
		SettingModule->RegisterSettings(
			"Project",
			"MessageSystem",
			"MessageData",
			LOCTEXT("MessageSystemName", "MessageSystem"),
			LOCTEXT("MessageSystemDescricption", "MessageSystem discription"),
			GetMutableDefault<UMessageManager>()
		);
	}

	auto& moduleMgr = FModuleManager::Get();

	if (moduleMgr.IsModuleLoaded("AssetTools")) {

		auto& assetTools = moduleMgr.LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		auto assetCategoryBit = assetTools.RegisterAdvancedAssetCategory(FName(TEXT("MessageSystem")), LOCTEXT("NewAssetCategory", "MessageAsset"));
		auto actions = MakeShareable(new MessageAssetActions(assetCategoryBit));

		assetTools.RegisterAssetTypeActions(actions);

		/*auto dataTableCategoryBit = assetTools.RegisterAdvancedAssetCategory(FName(TEXT("MessageSystem")), LOCTEXT("NewAssetCategory", "MessageDataTable"));
		auto dataTableActions = MakeShareable(new MessageDataTableActions(dataTableCategoryBit));

		assetTools.RegisterAssetTypeActions(dataTableActions);*/
	}

#endif
}

void FMessageSystemEditor::ShutdownModule() {
#if WITH_EDITOR
	ISettingsModule* SettingModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingModule != nullptr) {
		SettingModule->UnregisterSettings(
			"Project",
			"MessageSystem",
			"MessageData"
		);
	}
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMessageSystemEditor, MessageSystemEditor)