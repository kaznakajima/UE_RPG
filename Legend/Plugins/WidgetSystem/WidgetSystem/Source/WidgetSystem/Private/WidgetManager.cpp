// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManager.h"

/**
 * インスタンス
 */
UWidgetManager* UWidgetManager::Instance = nullptr;

/**
 * コンストラクタ 
 */
UWidgetManager::UWidgetManager(const FObjectInitializer& ObjectInitializer) {
	
}

/**
 * デストラクタ
 */
UWidgetManager::~UWidgetManager() {
	Instance = nullptr;
}

/**
 * インタンスの取得
 */
UWidgetManager* UWidgetManager::GetWidgetManager() {
	// インスタンスが見つからなければ生成
	if ( Instance == nullptr ) {
		Instance = NewObject<UWidgetManager>();
		Instance->AddToRoot();
	}
	return Instance;
}

UCustomWidgetBase* UWidgetManager::AddWidget(const UObject* WorldContextObject, FString Path, int32 Order) {

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
	if ( World == nullptr ) {
		return nullptr;
	}

	TSoftClassPtr<UCustomWidgetBase> WidgetClass = TSoftClassPtr<UCustomWidgetBase>(FSoftObjectPath(*Path)).LoadSynchronous();
	if ( WidgetClass == nullptr ) {
		return nullptr;
	}

	// 新しいウィジェットのインスタンスを作成します
	UCustomWidgetBase* Widget = CreateWidget<UCustomWidgetBase>(World, WidgetClass->StaticClass());
	ViewportWidgetArray.Add(Widget);
	Widget->AddToViewport(Order);
	return Widget;
}

void UWidgetManager::RemoveWidget(const UObject* WorldContextObject, UCustomWidgetBase* Widget) {
	if ( ViewportWidgetArray.Contains(Widget) ) {
		ViewportWidgetArray.Remove(Widget);
		Widget->RemoveFromParent();
		Widget = nullptr;
	}
}
