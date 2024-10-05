// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterDataManager.h"

/**
* インスタンス
*/
UMasterDataManager* UMasterDataManager::Instance = nullptr;

UMasterDataManager::UMasterDataManager(const FObjectInitializer& ObjectInitializer) {
}

UMasterDataManager::~UMasterDataManager() {
	Instance = nullptr;
}

UMasterDataManager* UMasterDataManager::GetMasterDataManager() {
	// インスタンスが見つからなければ生成
	if ( Instance == nullptr ) {
		Instance = NewObject<UMasterDataManager>();
		Instance->AddToRoot();
	}
	return Instance;
}
