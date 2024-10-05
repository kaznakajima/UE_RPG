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
	* コンストラクタ
	*/
	virtual void NativeConstruct() override;

	/**
	* ウィジェットを開いた際に呼ばれる処理
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Entry();
	/**
	* ウィジェットを閉じる際に呼ばれる処理
	*/
	UFUNCTION(BlueprintCallable)
	virtual void Remove();
};
