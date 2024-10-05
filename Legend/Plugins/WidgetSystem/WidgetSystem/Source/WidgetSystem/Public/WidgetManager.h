// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomWidgetBase.h"
#include "UObject/NoExportTypes.h"
#include "WidgetManager.generated.h"

/**
 * ウィジェットを管理するマネージャークラス
 */
UCLASS(config = Game, defaultconfig)
class WIDGETSYSTEM_API UWidgetManager : public UObject {
	GENERATED_BODY()

public:
	/**
	* コンストラクタ
	*/
	UWidgetManager(const FObjectInitializer& ObjectInitializer);

	/**
	* デストラクタ
	*/
	~UWidgetManager();

	/**
	* インスタンスの取得
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Singleton")
	static UWidgetManager* GetWidgetManager();
	
	/**
	* ウィジェットの追加
	*/
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	UCustomWidgetBase* AddWidget(const UObject* WorldContextObject, FString Path, int32 Order = 0);
	/**
	* ウィジェットの削除
	*/
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	void RemoveWidget(const UObject* WorldContextObject, UCustomWidgetBase* Widget);
	
	/**
	* 表示中のウィジェットを取得
	*/
	template<typename T>
	T* FindViewportWidget(const UObject* WorldContextObject);

protected:

	/**
	 * 表示中のウィジェット群
	 */
	UPROPERTY()
	TArray<TObjectPtr<UCustomWidgetBase>> ViewportWidgetArray;

	/**
	 * インスタンス
	 */
	static UWidgetManager* Instance;

};

template<typename T>
inline T* UWidgetManager::FindViewportWidget(const UObject* WorldContextObject) {
	for (UCustomWidgetBase* Widget : ViewportWidgetArray) {
		// インスタンスがT型の場合、そのポインタを返す
		T* CustomWidget = Cast<T>(Widget);
		if (CustomWidget) {
			return CustomWidget;
		}
	}
	return nullptr;
}
