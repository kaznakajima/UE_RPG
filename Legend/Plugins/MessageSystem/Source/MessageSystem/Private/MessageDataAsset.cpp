// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageDataAsset.h"

void UMessageDataAsset::Import() {
#if WITH_EDITORONLY_DATA
    if (!DataTable ||
        !DataTable->GetRowStruct()->IsChildOf(FMessageData::StaticStruct())) {
        return;
    }

    Data.Empty();
    auto Names = DataTable->GetRowNames();

    for (int i = 0; i < Names.Num(); i++) {
        auto record = DataTable->FindRow<FMessageData>(Names[i], FString());

        FMessageDataRecord asset;
        asset.ID = record->ID;
        asset.message = record->message;

        Data.Add(asset.ID, asset.message);
    }

#endif
}