// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "MessageDataAsset.generated.h"

// メッセージデータ構造体
USTRUCT()
struct FMessageData : public FTableRowBase {
	GENERATED_BODY()
public:

	// メッセージID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Message")
		int32 ID;

	// メッセージ本文
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Message")
		FText message;
};

// メッセージデータ構造体 (インゲーム用)
USTRUCT(BlueprintType)
struct FMessageDataRecord {
	GENERATED_BODY()
public:

	// メッセージID
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Message")
		int32 ID;

	// メッセージ本文
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Message")
		FText message;
};

UCLASS()
class MESSAGESYSTEM_API UMessageDataAsset : public UDataAsset {
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "Data")
		UDataTable* DataTable;
#endif
	UFUNCTION(meta = (CallInEditor = "true"))
		void Import();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
		TMap<int, FText> Data;
};
