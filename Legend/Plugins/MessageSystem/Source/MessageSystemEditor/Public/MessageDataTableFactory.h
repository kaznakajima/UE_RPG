// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/DataTableFactory.h"
#include "MessageDataTableFactory.generated.h"

UCLASS()
class MESSAGESYSTEMEDITOR_API UMessageDataTableFactory : public UDataTableFactory {
	GENERATED_BODY()

public:
	UMessageDataTableFactory(const FObjectInitializer& ObjectInitializer);

public:

	virtual bool DoesSupportClass(UClass* Class) override;

	virtual UClass* ResolveSupportedClass() override;

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
