// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageAssetFactory.h"
#include "MessageSystem.h"
#include "MessageDataAsset.h"

UMessageAssetFactory::UMessageAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	SupportedClass = UMessageDataAsset::StaticClass();
	bCreateNew = true;
}

bool UMessageAssetFactory::DoesSupportClass(UClass* Class) {
	return (Class == UMessageDataAsset::StaticClass());
}

UClass* UMessageAssetFactory::ResolveSupportedClass() {
	return UMessageDataAsset::StaticClass();
}

UObject* UMessageAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {

	FStaticConstructObjectParameters Params(InClass);
	Params.Outer = InParent;
	Params.Name = InName;
	Params.SetFlags = Flags;

	UMessageDataAsset* MessageAsset = CastChecked<UMessageDataAsset>(StaticConstructObject_Internal(Params));
	return MessageAsset;
}