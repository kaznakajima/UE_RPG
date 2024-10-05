// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MasterDataManager.generated.h"

/**
 * マスターデータを管理するクラス
 */
UCLASS(config = Game, defaultconfig)
class MASTERDATASYSTEM_API UMasterDataManager : public UObject {
	GENERATED_BODY()

public:
	/**
	* コンストラクタ
	*/
	UMasterDataManager(const FObjectInitializer& ObjectInitializer);

	/**
	* デストラクタ
	*/
	~UMasterDataManager();

	/**
	* インスタンスの取得
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Singleton")
	static UMasterDataManager* GetMasterDataManager();

protected:

	/**
	* インスタンス
	*/
	static UMasterDataManager* Instance;
};
