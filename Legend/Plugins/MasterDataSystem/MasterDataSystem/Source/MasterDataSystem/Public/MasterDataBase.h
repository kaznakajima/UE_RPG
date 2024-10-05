// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "MasterDataBase.generated.h"

/**
 * マスターデータの基底クラス
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
	* データのインポート
	*/
	UFUNCTION(meta = (CallInEditor = "true"))
	virtual void Import();

	/**
	* 構造体取得用の仮想関数
	*/
	virtual void* GetStructByType(const std::type_info& Type) const;

	/**
	* 構造体の取得
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
