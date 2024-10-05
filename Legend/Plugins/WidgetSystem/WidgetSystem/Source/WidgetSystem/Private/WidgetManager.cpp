// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManager.h"

/**
 * �C���X�^���X
 */
UWidgetManager* UWidgetManager::Instance = nullptr;

/**
 * �R���X�g���N�^ 
 */
UWidgetManager::UWidgetManager(const FObjectInitializer& ObjectInitializer) {
	
}

/**
 * �f�X�g���N�^
 */
UWidgetManager::~UWidgetManager() {
	Instance = nullptr;
}

/**
 * �C���^���X�̎擾
 */
UWidgetManager* UWidgetManager::GetWidgetManager() {
	// �C���X�^���X��������Ȃ���ΐ���
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

	// �V�����E�B�W�F�b�g�̃C���X�^���X���쐬���܂�
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
