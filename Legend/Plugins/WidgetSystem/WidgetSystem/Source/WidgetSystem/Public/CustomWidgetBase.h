// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class WIDGETSYSTEM_API UCustomWidgetBase : public UUserWidget {
	GENERATED_BODY()
	
public:

	/**
	* �R���X�g���N�^
	*/
	virtual void NativeConstruct() override;

	/**
	* �E�B�W�F�b�g���J�����ۂɌĂ΂�鏈��
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Entry();
	/**
	* �E�B�W�F�b�g�����ۂɌĂ΂�鏈��
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Remove();
};
