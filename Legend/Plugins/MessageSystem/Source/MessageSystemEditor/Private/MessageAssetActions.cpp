// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageAssetActions.h"
#include "MessageDataAsset.h"

/// <summary>
/// コンストラクタ
/// </summary>
MessageAssetActions::MessageAssetActions() 
	: name( FText::FromString(TEXT("MessageAsset")) )
	, assetCategoryBit( EAssetTypeCategories::Misc ){
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="assetCategoryBit"></param>
MessageAssetActions::MessageAssetActions(EAssetTypeCategories::Type assetCategoryBit)
	: name(FText::FromString(TEXT("MessageAsset")))
	, assetCategoryBit( assetCategoryBit ) {
}

/// <summary>
/// アセット名を取得
/// </summary>
/// <returns></returns>
FText MessageAssetActions::GetName() const {
	return name;
}

/// <summary>
/// アセットカラーを取得
/// </summary>
/// <returns></returns>
FColor MessageAssetActions::GetTypeColor() const {
	return FColor::Red;
}

/// <summary>
/// 自身が扱うクラスを取得
/// </summary>
/// <returns></returns>
UClass* MessageAssetActions::GetSupportedClass() const {
	return UMessageDataAsset::StaticClass();
}

/// <summary>
/// アセットのカテゴリを返す
/// </summary>
/// <returns></returns>
uint32 MessageAssetActions::GetCategories() {
	return assetCategoryBit;
}

/// <summary>
/// アセットを開いた時の処理
/// </summary>
/// <param name="InObjects"></param>
/// <param name="EditWithinLevelEditor"></param>
void MessageAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor) {
	for (int i = 0; i < InObjects.Num(); ++i) {
		FSimpleAssetEditor::CreateEditor( EToolkitMode::Standalone, EditWithinLevelEditor, InObjects[i] );
	}
};