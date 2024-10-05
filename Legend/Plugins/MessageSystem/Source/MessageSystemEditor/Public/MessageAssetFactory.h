// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MessageAssetFactory.generated.h"

UCLASS()
class MESSAGESYSTEMEDITOR_API UMessageAssetFactory : public UFactory {
	GENERATED_BODY()

public:

	UMessageAssetFactory(const FObjectInitializer& ObjectInitializer);

public:

	virtual bool DoesSupportClass(UClass* Class) override;

	virtual UClass* ResolveSupportedClass() override;

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
