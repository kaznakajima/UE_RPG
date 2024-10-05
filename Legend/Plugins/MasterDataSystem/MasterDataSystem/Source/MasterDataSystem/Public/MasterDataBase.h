// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "MasterDataBase.generated.h"

/**
 * �}�X�^�[�f�[�^�̊��N���X
 */
UCLASS()
class MASTERDATASYSTEM_API UMasterDataBase : public UDataAsset {
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "Data")
	UDataTable* DataTable;
#endif

	/**
	* �f�[�^�̃C���|�[�g
	*/
	UFUNCTION(meta = (CallInEditor = "true"))
	virtual void Import();

	/**
	* �\���̎擾�p�̉��z�֐�
	*/
	virtual void* GetStructByType(const std::type_info& Type) const;

	/**
	* �\���̂̎擾
	*/
	template<typename T>
	T GetStruct() const;
};

template<typename T>
inline T UMasterDataBase::GetStruct() const {
	void* StructPtr = GetStructByType( typeid(T) );
	if ( StructPtr ) {
		return *static_cast<T*>(StructPtr);
	}
	else {
		return nullptr;
	}
}
