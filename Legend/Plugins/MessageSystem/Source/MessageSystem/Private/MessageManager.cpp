// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageManager.h"

UMessageManager* UMessageManager::instance = nullptr;

UMessageManager::UMessageManager(const FObjectInitializer& ObjectInitializer) {
}

UMessageManager* UMessageManager::GetInstance()
{
	if (instance == nullptr) {
		instance = NewObject<UMessageManager>(GetTransientPackage(), FName("MessageSingletonClass"));
		instance->AddToRoot();
	}
	return instance;
}

/// <summary>
/// メッセージデータアセットの取得
/// </summary>
/// <param name="WorldContextObject"></param>
/// <returns></returns>
TArray<UMessageDataAsset*> UMessageManager::GetMessageDataAsset(const UObject* WorldContextObject) {
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
	if (World == nullptr) {
		return TArray<UMessageDataAsset*>();
	}

	// ゲームのインスタンスからmanagerクラスを取得
	UMessageManager* MessageManager = UMessageManager::GetInstance();

	if ( MessageManager == nullptr ) {
		return TArray<UMessageDataAsset*>();
	}

	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ELanguageType"), true);

	FString Key = EnumPtr->GetNameStringByValue((int32)MessageManager->LanguageType);
	for (int i = 0; i < MessageManager->MessageDataAssetPath.Num(); ++i) {
		if (MessageManager->MessageDataAsset[i] == nullptr) {
			// データアセットのファイルパス
			FString DataAssetPath = MessageManager->MessageDataAssetPath[i].ToString();
			bool MatchLanguage = DataAssetPath.Contains(Key);
			if ( MatchLanguage == false ) {
				continue;
			}

			// アセットを読み込む
			MessageManager->MessageDataAsset[i] = Cast<UMessageDataAsset>(StaticLoadObject(UMessageDataAsset::StaticClass(), nullptr, *DataAssetPath));
		}
	}

	return MessageManager->MessageDataAsset;
}

// 任意のメッセージデータを取得
bool UMessageManager::GetMessageData(const UObject* WorldContextObject, int MessageID, FText& OutMessage) {
	TArray<UMessageDataAsset*> DataAsset = GetMessageDataAsset(WorldContextObject);
	for (int i = 0; i < DataAsset.Num(); ++i) {
		if (DataAsset[i] != nullptr) {
			FText text = *DataAsset[i]->Data.Find(MessageID);
			if ( !text.IsEmpty() ) {
				OutMessage = text;
			}
		}
		else {
			return false;
		}
	}
	return true;
}