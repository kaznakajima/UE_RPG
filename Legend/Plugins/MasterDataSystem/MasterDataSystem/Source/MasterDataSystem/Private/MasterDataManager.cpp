// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterDataManager.h"

/**
* �C���X�^���X
*/
UMasterDataManager* UMasterDataManager::Instance = nullptr;

UMasterDataManager::UMasterDataManager(const FObjectInitializer& ObjectInitializer) {
}

UMasterDataManager::~UMasterDataManager() {
	Instance = nullptr;
}

UMasterDataManager* UMasterDataManager::GetMasterDataManager() {
	// �C���X�^���X��������Ȃ���ΐ���
	if ( Instance == nullptr ) {
		Instance = NewObject<UMasterDataManager>();
		Instance->AddToRoot();
	}
	return Instance;
}
