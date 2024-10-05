// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomWidgetBase.h"
#include "UObject/NoExportTypes.h"
#include "WidgetManager.generated.h"

/**
 * �E�B�W�F�b�g���Ǘ�����}�l�[�W���[�N���X
 */
UCLASS(config = Game, defaultconfig)
class WIDGETSYSTEM_API UWidgetManager : public UObject {
	GENERATED_BODY()

public:
	/**
	* �R���X�g���N�^
	*/
	UWidgetManager(const FObjectInitializer& ObjectInitializer);

	/**
	* �f�X�g���N�^
	*/
	~UWidgetManager();

	/**
	* �C���X�^���X�̎擾
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Singleton")
	static UWidgetManager* GetWidgetManager();
	
	/**
	* �E�B�W�F�b�g�̒ǉ�
	*/
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	UCustomWidgetBase* AddWidget(const UObject* WorldContextObject, FString Path, int32 Order = 0);
	/**
	* �E�B�W�F�b�g�̍폜
	*/
	UFUNCTION(BlueprintCallable, Category = "Singleton")
	void RemoveWidget(const UObject* WorldContextObject, UCustomWidgetBase* Widget);
	
	/**
	* �\�����̃E�B�W�F�b�g���擾
	*/
	template<typename T>
	T* FindViewportWidget(const UObject* WorldContextObject);

protected:

	/**
	 * �\�����̃E�B�W�F�b�g�Q
	 */
	UPROPERTY()
	TArray<TObjectPtr<UCustomWidgetBase>> ViewportWidgetArray;

	/**
	 * �C���X�^���X
	 */
	static UWidgetManager* Instance;

};

template<typename T>
inline T* UWidgetManager::FindViewportWidget(const UObject* WorldContextObject) {
	for (UCustomWidgetBase* Widget : ViewportWidgetArray) {
		// �C���X�^���X��T�^�̏ꍇ�A���̃|�C���^��Ԃ�
		T* CustomWidget = Cast<T>(Widget);
		if (CustomWidget) {
			return CustomWidget;
		}
	}
	return nullptr;
}
