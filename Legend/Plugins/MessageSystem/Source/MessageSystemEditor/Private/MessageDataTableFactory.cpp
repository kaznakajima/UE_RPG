// Fill out your copyright notice in the Description page of Project Settings.

#include "MessageDataTableFactory.h"
#include "MessageDataTable.h"
#include "MessageDataAsset.h"

UMessageDataTableFactory::UMessageDataTableFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	SupportedClass = UMessageDataTable::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

bool UMessageDataTableFactory::DoesSupportClass(UClass* Class) {
	return (Class == UMessageDataTable::StaticClass());
}

UClass* UMessageDataTableFactory::ResolveSupportedClass() {
	return UMessageDataTable::StaticClass();
}

UObject* UMessageDataTableFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {

	FStaticConstructObjectParameters Params(InClass);
	Params.Outer = InParent;
	Params.Name = InName;
	Params.SetFlags = Flags;

	UMessageDataTable* DataTable = CastChecked<UMessageDataTable>(StaticConstructObject_Internal(Params));
	DataTable->RowStruct = FMessageData::StaticStruct();

	DataTable->MarkPackageDirty();
	DataTable->PostEditChange();
	DataTable->SetFlags(RF_Public);

	return DataTable;
}