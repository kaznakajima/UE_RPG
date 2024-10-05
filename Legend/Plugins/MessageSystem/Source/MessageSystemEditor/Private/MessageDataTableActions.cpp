// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageDataTableActions.h"

/// <summary>
/// コンストラクタ
/// </summary>
MessageDataTableActions::MessageDataTableActions()
	: name(FText::FromString(TEXT("MessageDataTable")))
	, assetCategoryBit(EAssetTypeCategories::Misc) {
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="assetCategoryBit"></param>
MessageDataTableActions::MessageDataTableActions(EAssetTypeCategories::Type assetCategoryBit)
	: name(FText::FromString(TEXT("MessageDataTable")))
	, assetCategoryBit(assetCategoryBit) {
}


/// <summary>
/// アセット名を取得
/// </summary>
/// <returns></returns>
FText MessageDataTableActions::GetName() const {
	return name;
}

/// <summary>
/// アセットカラーを取得
/// </summary>
/// <returns></returns>
FColor MessageDataTableActions::GetTypeColor() const {
	return FColor::Green;
}

/// <summary>
/// 自身が扱うクラスを取得
/// </summary>
/// <returns></returns>
UClass* MessageDataTableActions::GetSupportedClass() const {
	return UMessageDataTable::StaticClass();
}

/// <summary>
/// アセットのカテゴリを返す
/// </summary>
/// <returns></returns>
uint32 MessageDataTableActions::GetCategories() {
	return assetCategoryBit;
}

/// <summary>
/// アセットを開いた時の処理
/// </summary>
/// <param name="InObjects"></param>
/// <param name="EditWithinLevelEditor"></param>
void MessageDataTableActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor) {
	for (int i = 0; i < InObjects.Num(); ++i) {
		FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects[i]);
	}
};
