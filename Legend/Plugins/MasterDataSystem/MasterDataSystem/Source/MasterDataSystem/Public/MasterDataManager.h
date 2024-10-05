// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MasterDataManager.generated.h"

/**
 * �}�X�^�[�f�[�^���Ǘ�����N���X
 */
UCLASS(config = Game, defaultconfig)
class MASTERDATASYSTEM_API UMasterDataManager : public UObject {
	GENERATED_BODY()

public:
	/**
	* �R���X�g���N�^
	*/
	UMasterDataManager(const FObjectInitializer& ObjectInitializer);

	/**
	* �f�X�g���N�^
	*/
	~UMasterDataManager();

	/**
	* �C���X�^���X�̎擾
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Singleton")
	static UMasterDataManager* GetMasterDataManager();

protected:

	/**
	* �C���X�^���X
	*/
	static UMasterDataManager* Instance;
};
