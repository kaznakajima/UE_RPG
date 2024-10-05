// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MessageDataAsset.h"
#include "MessageManager.generated.h"

UENUM(BlueprintType)
enum class ELanguageType : uint8 {
	JP,
	US,
	FS,
	DE,
};

UCLASS(config = Game, defaultconfig)
class MESSAGESYSTEM_API UMessageManager : public UObject {
	GENERATED_BODY()

public:

	UMessageManager(const FObjectInitializer& ObjectInitializer);

	// インスタンス
	static UMessageManager* instance;

	// インスタンスを取得
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	static UMessageManager* GetInstance();

	// インスタンスの削除
	virtual void BeginDestroy() override {
		Super::BeginDestroy();

		if (instance == nullptr && instance == this) {
			instance = nullptr;
		}
	}

	// データアセットのファイルパス
	UPROPERTY(EditAnywhere, Category = "Data", Config, meta = (AllowedClasses = "MessageDataAsset"))
		TArray<FSoftObjectPath> MessageDataAssetPath;

	// メッセージ情報
	UPROPERTY(BlueprintReadOnly, Category = "Data")
		TArray <UMessageDataAsset*> MessageDataAsset;

	// 言語情報
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		ELanguageType LanguageType;

	// データアセットの取得
	UFUNCTION(BlueprintCallable, Category = "Data", meta = (WorldContext = "WorldContextObject"))
		static TArray<UMessageDataAsset*> GetMessageDataAsset(const UObject* WorldContextObject);

	// 任意のメッセージデータを取得
	UFUNCTION(BlueprintCallable, Category = "Data", meta = (WorldContext = "WorldContextObject"))
		static bool GetMessageData(const UObject* WorldContextObject, int MessageID, FText& OutMessage);
};
