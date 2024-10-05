// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class MESSAGESYSTEMEDITOR_API MessageAssetActions : public FAssetTypeActions_Base {
public:
	MessageAssetActions();
	MessageAssetActions(EAssetTypeCategories::Type AssetCategoryBit);

public:
	virtual FText GetName() const override;
	virtual uint32 GetCategories() override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;

	virtual void OpenAssetEditor(const TArray<UObject*> &InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>() ) override;

private:
	FText name;
	EAssetTypeCategories::Type assetCategoryBit;

};
